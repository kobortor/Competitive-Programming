#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define allof(x) (x).begin(), (x).end()

const int MAXN = 255;
const int MAXM = 2 * MAXN * MAXN + 5;

const int A = 0;
const int B = 1;
bool grid[MAXM];

int R, C;
struct triple {
    int t, i, j;
    triple(int _t, int _i, int _j) : t(_t), i(_i), j(_j) {}
    bool operator<(triple tt) const {
        auto t1 = tuple<int, int, int>(t, i, j);
        auto t2 = tuple<int, int, int>(tt.t, tt.i, tt.j);
        return t1 < t2;
    }
    bool operator==(triple tt) const {
        return t == tt.t && i == tt.i && j == tt.j;
    }
    operator int() const {
        return t * MAXN * MAXN + i * MAXN + j;
    }
};

int tidx(int t, int i, int j) {
    return (int)triple(t, i, j);
}

ostream& operator<<(ostream &os, const triple &t) {
    return os << "(" << (t.t ? "B" : "A") << " " << t.i << " " << t.j << ")";
}

bool good(triple t) {
    return 1 <= t.i && t.i <= R && 1 <= t.j && t.j <= C;
}

const int UP = 1;
const int RIGHT = 2;
const int DOWN = 4;
const int LEFT = 8;
const int ALL_SIDES = 15;

const int NODE_U = MAXM - 1;
const int NODE_R = MAXM - 2;
const int NODE_L = MAXM - 3;
const int NODE_D = MAXM - 4;
pii outside_nodes[] = {
    pii(NODE_U, UP), 
    pii(NODE_R, RIGHT), 
    pii(NODE_D, DOWN), 
    pii(NODE_L, LEFT)
};

int dsu[MAXM];
int side[MAXM];
vector<int> adj[MAXM];

int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

bool is_arty[MAXM];
int cnt;
int disc[MAXM];
int low[MAXM];
void dfs(int pos, int par) {
    disc[pos] = low[pos] = cnt++;

    int seen = 0;
    for (int i : adj[pos]) {
        if (i == par) continue;

        if (disc[i] == -1) {
            seen++;
            dfs(i, pos);

            low[pos] = min(low[pos], low[i]);

            if (par == -1) {
                is_arty[pos] |= (seen >= 2);
            } else {
                is_arty[pos] |= (low[i] >= disc[pos]);
            }
        } else {
            low[pos] = min(low[pos], disc[i]);
        }
    }
}

bool vis[MAXM];
vector<int> collect_nodes(int pos) {
    vector<int> nodes;
    nodes.push_back(pos);
    vis[pos] = true;

    for (int i = 0; i < nodes.size(); i++) {
        for (int j : adj[nodes[i]]) {
            if (!vis[j]) {
                vis[j] = true;
                nodes.push_back(j);
            }
        }
    }
    for (int nd : nodes) {
        vis[nd] = 0;
    }
    return nodes;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> R >> C;
        
        for (int i = 0; i < MAXM; i++) {
            dsu[i] = i;
            side[i] = 0;
            grid[i] = 0;
            is_arty[i] = false;
            adj[i].clear();
        }

        for (int i = 0; i < R; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < C; j++) {
                grid[tidx(A, i + 1, j + 1)] = (s[j * 2    ] == '0');
                grid[tidx(B, i + 1, j + 1)] = (s[j * 2 + 1] == '0');
            }
        }

        vector<pair<triple, triple>> edges;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (i % 2 == j % 2) {
                    edges.push_back({{A, i, j}, {A, i  , j-1}});
                    edges.push_back({{A, i, j}, {B, i-1, j  }});
                    edges.push_back({{A, i, j}, {B, i  , j-1}});
                    edges.push_back({{A, i, j}, {B, i  , j  }});
                    edges.push_back({{A, i, j}, {A, i+1, j  }});

                    edges.push_back({{B, i, j}, {A, i  , j  }});
                    edges.push_back({{B, i, j}, {B, i-1, j  }});
                    edges.push_back({{B, i, j}, {A, i  , j+1}});
                    edges.push_back({{B, i, j}, {B, i  , j+1}});
                    edges.push_back({{B, i, j}, {A, i+1, j  }});
                } else {
                    edges.push_back({{A, i, j}, {B, i  , j-1}});
                    edges.push_back({{A, i, j}, {A, i-1, j  }});
                    edges.push_back({{A, i, j}, {B, i-1, j  }});
                    edges.push_back({{A, i, j}, {B, i  , j  }});
                    edges.push_back({{A, i, j}, {A, i  , j+1}});

                    edges.push_back({{B, i, j}, {B, i  , j-1}});
                    edges.push_back({{B, i, j}, {A, i  , j  }});
                    edges.push_back({{B, i, j}, {A, i  , j+1}});
                    edges.push_back({{B, i, j}, {B, i+1, j  }});
                    edges.push_back({{B, i, j}, {A, i+1, j  }});
                }
            }
        }
        for (auto &[u, v] : edges) {
            if (v < u) swap(u, v);
        }
        sort(allof(edges));
        edges.erase(unique(allof(edges)), edges.end());

        vector<pii> edge_idxs;

        for (auto &[u, v] : edges) {
            if (good(u) && good(v)) {
                edge_idxs.push_back({u, v});
            }
        }

        for (int t = A; t <= B; t++) {
            for (int i = 1; i <= R; i++) {
                for (int j = 1; j <= C; j++) {
                    int idx = tidx(t, i, j);
                    if (i == 1 && (t == A || j % 2 == 1    )) side[idx] |= UP;
                    if (j == C && (t != A || i % 2 != C % 2)) side[idx] |= RIGHT;
                    if (i == R && (t != A || j % 2 == R % 2)) side[idx] |= DOWN;
                    if (j == 1 && (t == A || i % 2 != 1    )) side[idx] |= LEFT;
                }
            }
        }

        for (auto [u, v] : edge_idxs) {
            if (grid[(int)u] && grid[(int)v]) {
                int fu = find((int)u);
                int fv = find((int)v);
                if (fu != fv) {
                    dsu[fu] = fv;
                }

                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        int ans = -1;
        for (int t = A; t <= B; t++) {
            for (int i = 1; i <= R; i++) {
                for (int j = 1; j <= C; j++) {
                    int idx = tidx(t, i, j);
                    if (!grid[idx] || dsu[idx] != idx) continue;

                    vector<int> nodes = collect_nodes(idx);

                    int all_sides = 0;
                    for (int nd : nodes) all_sides |= side[nd];
                    if (all_sides != ALL_SIDES) continue;

                    for (auto [nd_out, sd] : outside_nodes) {
                        for (int nd_in : nodes) {
                            if (side[nd_in] & sd) {
                                adj[nd_out].push_back(nd_in);
                                adj[nd_in].push_back(nd_out);
                            }
                        }

                        cnt = 0;
                        memset(disc, -1, sizeof disc);
                        memset(low, -1, sizeof low);
                        dfs(nd_out, -1);

                        for (int nd_in : nodes) {
                            if (side[nd_in] & sd) {
                                adj[nd_out].erase(find(allof(adj[nd_out]), nd_in));
                                adj[nd_in].erase(find(allof(adj[nd_in]), nd_out));
                            }
                        }
                    }

                    if (all_of(allof(nodes), [](int i){return is_arty[i];})) {
                        ans = nodes.size();
                    }
                }
            }
        }

        if (ans == -1) {
            cout << "NO MINIMAL CORRIDOR\n";
        } else {
            cout << ans << "\n";
        }
    }
}
