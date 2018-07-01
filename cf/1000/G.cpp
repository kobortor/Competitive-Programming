#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

int N, Q;

ll val[MAXN];
ll above[MAXN];
ll below[MAXN];
pll par[MAXN][20];
ll cost_par[MAXN];
ll dep[MAXN];

vector<pll> adj[MAXN];

void dfs1(int pos){
    below[pos] = val[pos];
    for(pll p : adj[pos]){
        if(par[pos][0].first == p.first){
            continue;
        }

        dep[p.first] = dep[pos] + 1;
        cost_par[p.first] = p.second;
        par[p.first][0].first = pos;

        dfs1(p.first);

        below[pos] += max(0ll, below[p.first] - 2 * p.second);
    }

    for(pll p : adj[pos]){
        if(par[pos][0].first == p.first){
            continue;
        }

        ll cost = below[pos] - max(0ll, below[p.first] - 2 * p.second) - p.second;

        par[p.first][0].second = cost;
    }
}

void dfs2(int pos, ll abv){
    for(int a = 0; a + 1 < 20; a++){
        ll nxt = par[pos][a].first;
        if(nxt == -1){
            break;
        }

        par[pos][a + 1] = pll(par[nxt][a].first, par[pos][a].second + par[nxt][a].second);
    }

    above[pos] = abv;

    for(pll p : adj[pos]){
        if(par[pos][0].first == p.first){
            continue;
        }

        ll nxtabv = abv + below[pos] - max(0ll, below[p.first] - 2 * p.second);
        dfs2(p.first, max(0ll, nxtabv - p.second * 2));
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(par, -1, sizeof par);

    cin >> N >> Q;

    for(int a = 1; a <= N; a++){
        cin >> val[a];
    }

    for(int a = 1; a <= N - 1; a++){
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dfs1(1);
    dfs2(1, 0);

    while(Q--){
        int u, v;
        cin >> u >> v;
        if(dep[u] < dep[v]){
            swap(u, v);
        }

        int diff = dep[u] - dep[v];
        int tmp_pos = u;
        for(int a = 0; a < 20; a++){
            if(diff & (1 << a)){
                tmp_pos = par[tmp_pos][a].first;
            }
        }

        if(tmp_pos == v){
            //v is directly above u
            ll ans = below[u];
            for(int a = 0; a < 20; a++){
                if(diff & (1 << a)){
                    ans += par[u][a].second;
                    u = par[u][a].first;
                }
            }

            cout << ans + above[v] << "\n";
        } else {
            ll ans = below[u] + below[v];
            for(int a = 0; a < 20; a++){
                if(diff & (1 << a)){
                    ans += par[u][a].second;
                    u = par[u][a].first;
                }
            }

            for(int a = 19; a >= 0; a--){
                int nxtu = par[u][a].first;
                int nxtv = par[v][a].first;
                if(nxtu != -1 && nxtv != -1 && nxtu != nxtv){
                    ans += par[u][a].second;
                    ans += par[v][a].second;

                    u = nxtu;
                    v = nxtv;
                }
            }

            ll lca = par[u][0].first;

            ans += below[lca] + above[lca];

            ans -= max(0ll, below[u] - 2 * cost_par[u]);
            ans -= max(0ll, below[v] - 2 * cost_par[v]);

            ans -= cost_par[u];
            ans -= cost_par[v];

            cout << ans << "\n";
        }
    }
}
