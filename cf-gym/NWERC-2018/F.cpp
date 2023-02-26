#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define rep(i, a, b) for (int i = a; i < (b); ++i)

struct RollbackUF {
    vi e; vector<pii> st;
    RollbackUF (int n) : e(n, -1) {}
    int size(int x) {return -e[find(x)];}
    int find(int x) {return e[x] < 0 ? x : find(e[x]);}
    int time() {return st.size();}
    void rollback(int t) {
        for (int i = time(); i --> t;) 
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

struct Edge {int a, b; ll w; };
struct Node {
    Edge key;
    Node *l, *r;
    ll delta;
    void prop() {
        key.w += delta;
        if (l) l->delta += delta;
        if (r) r->delta += delta;
        delta = 0;
    }
    Edge top() {prop(); return key;}
};
Node *merge (Node *a, Node *b) {
    if (!a || !b) return a ?: b;
    a->prop(), b->prop();
    if (a->key.w > b->key.w) swap(a, b);
    swap(a->l, (a->r = merge(b, a->r)));
    return a;
}

void pop(Node *&a) { a->prop(); a = merge(a->l, a->r); }

pair<ll, vi> dmst(int n, int r, vector<Edge> &g) {
    RollbackUF uf(n);
    vector<Node*> heap(n);
    for (Edge e : g) heap[e.b] = merge(heap[e.b], new Node{e});
    ll res = 0;
    vi seen(n, -1), path(n), par(n);
    seen[r] = r;
    vector<Edge> Q(n), in(n, {-1, -1}), comp;
    deque<tuple<int, int, vector<Edge>>> cycs;
    rep(s, 0, n) {
        int u = s, qi = 0, w;
        while (seen[u] < 0) {
            if (!heap[u]) {
                return {-1, {}};
            }
            Edge e = heap[u]->top();
            heap[u]->delta -= e.w, pop(heap[u]);
            Q[qi] = e, path[qi++] = u, seen[u] = s;
            res += e.w, u = uf.find(e.a);
            if (seen[u] == s) {
                Node *cyc = 0;
                int end = qi, time = uf.time();
                do {
                    cyc = merge(cyc, heap[w = path[--qi]]);
                } while (uf.join(u, w));
                u = uf.find(u), heap[u] = cyc, seen[u] = -1;
                cycs.push_front({u, time, {&Q[qi], &Q[end]}});
            }
        }
        rep(i, 0, qi) in[uf.find(Q[i].b)] = Q[i];
    }
    for (auto &[u, t, comp] : cycs) {
        uf.rollback(t);
        Edge inEdge = in[u];
        for (auto &e : comp) in[uf.find(e.b)] = e;
        in[uf.find(inEdge.b)] = inEdge;
    }
    rep(i, 0, n) par[i] = in[i].a;
    return {res, par};
}

const int MAXN = 2505;

int n;
ll x[MAXN];
ll s[MAXN];
ll best[MAXN];
ll grid[MAXN][MAXN];
bool reach[MAXN][MAXN];

vector<int> shortcut_out[MAXN];
bool grouped[MAXN];

int32_t main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> s[i];
        shortcut_out[x[i]].push_back(i);
        for (int j = 0; j <= n;j ++){ 
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        queue<int> q;
        q.push(i);
        reach[i][i] = true;
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            for (int out : shortcut_out[fr]) {
                if (!reach[i][out]) {
                    reach[i][out] = true;
                    q.push(out);
                }
            }
        }
    }

    vector<pair<vector<int>, ll>> groups;
    groups.push_back({{0}, 0});

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (grouped[i]) continue;

        if (reach[i][x[i]]) {  // can be root
            vector<int> group;
            ll shortcut_sum = 0;
            for (int j = 1; j <= n; j++) {
                if (reach[i][j]) {
                    grouped[j] = true;
                    group.push_back(j);
                    shortcut_sum += s[j];
                }
            }
            groups.push_back({group, shortcut_sum});
            // cout << "Group add base cost " << shortcut_sum << endl;
            ans += shortcut_sum;
        }
    }

    vector<Edge> edges;
    int new_n = groups.size();
    int new_r = 0;

    for (int i = 0; i < new_n; i++) {
        for (int j = 1; j < new_n; j++) {
            if (i == j) continue;

            ll min_edge = 1e12;
            for (int out : groups[i].first) {
                for (int in : groups[j].first) {
                    // cout << "Try " << out << " -> " << in << endl;
                    min_edge = min(min_edge, grid[in][out] - s[in]);
                }
            }
            // cout << "Add edge " << i << " to " << j << " weight " << min_edge << endl;
            edges.push_back({i, j, min_edge});
        }
    }
    ll newcost = dmst(new_n, new_r, edges).first;
    // cout << "Newcost = " << newcost << endl;
    ans += newcost;
    cout << ans << endl;
}
