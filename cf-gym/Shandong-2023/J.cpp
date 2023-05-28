#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, M, Q, V;
struct DSU {
    vector<int> dsu;
    DSU() {
        dsu = vector<int>(MAXN);
        for (int i = 0; i < MAXN; i++) {
            dsu[i] = i;
        }
    }
    int find(int x) {
        return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
    }
};

struct Edge {
    ll u, v, w;
};

vector<pll> adj[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q >> V;

    vector<Edge> edges;
    
    for (int i = 0; i < M; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }

    vector<DSU> dsus;
    ll checkMasks = 0;
    for (int i = 61; i >= 0; i--) {
        checkMasks |= (1ll << i);
        if (checkMasks >= V) {
            // add DSU
            dsus.emplace_back();
            DSU &d = dsus.back();
            for (Edge e : edges) {
                if ((e.w & checkMasks) == checkMasks) {
                    int fu = d.find(e.u);
                    int fv = d.find(e.v);
                    d.dsu[fu] = fv;
                }
            }

            checkMasks &= ~(1ll << i);
        } else {
            // Must keep at 1
        }
    }

    while (Q--) {
        int u, v;
        cin >> u >> v;

        bool good = false;
        for (DSU &d : dsus) {
            if (d.find(u) == d.find(v)) {
                good = true;
                break;
            }
        }
        cout << (good ? "Yes\n" : "No\n");
    }
}
