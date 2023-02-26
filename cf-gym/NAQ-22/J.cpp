#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e17;

struct Dinic
{
    
    struct Edge
    {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0ll); }
    };

    vector<int> lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}

    void add_edge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, (int)adj[b].size(), c, c});
        adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
    }

    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < adj[v].size(); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1) {
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p;
                    adj[e.to][e.rev].c += p;
                    return p;
                }
            }
        }
        return 0;
    }

    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        for (int L = 0; L <= 30; L++) {
            do {

                lvl = ptr = vector<int>(q.size());
                int qi = 0, qe = lvl[s] = 1;
                while (qi < qe && !lvl[t]) {
                    int v = q[qi++];
                    for (Edge e : adj[v]) {
                        if (!lvl[e.to] && e.c >> (30 - L)) {
                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                        }
                    }
                }
                while (ll p = dfs(s, t, INF)) flow += p;

            } while (lvl[t]);
        }
        return flow;
    }

};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m, t; cin >> n >> m >> t;
    vector<string> a(n);
    for (string &s : a)
        cin >> s;

    int dr[5] = {0, 1, 0, -1, 0};
    int dc[5] = {1, 0, -1, 0, 0};

    auto out_of_bounds = [&](int r, int c) {
        return (r < 0 || c < 0 || r >= n || c >= m);
    };

    auto to_ind = [&](int R, int C, int T) {
        int hv = R * m + C;
        int hh = T * (n * m);
        return hh + hv + 1;
    };

    // Dinic w/ n * m * (t + 1) + 2 nodes, named "helper"
    Dinic helper(n * m * (t + 1) + 2);

    int source = 0, sink = n * m * (t + 1) + 1;
    for (int k = 0; k < t; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '#') continue;
                for (int x = 0; x < 5; x++) {
                    int nr = i + dr[x];
                    int nc = j + dc[x];
                    if (out_of_bounds(nr, nc)) continue;
                    if (a[nr][nc] == '#') continue;

                    helper.add_edge(to_ind(i, j, k), to_ind(nr, nc, k + 1), 1);

                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (a[i][j] == 'P') {
                helper.add_edge(0, to_ind(i, j, 0), 1);
            }
            else if (a[i][j] == 'E') {
                for (int k = 0; k <= t; k++) {
                    helper.add_edge(to_ind(i, j, k), sink, 1);
                }
            }

        }
    }

    cout << helper.calc(source, sink) << "\n";

}
