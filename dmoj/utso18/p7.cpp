#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const ll mod = 1e9 + 7;

ll N, Q;
vector<ll> adj[MAXN];
ll P[MAXN];
bool used[MAXN];
ll sz[MAXN];

//<parent centroid, <linkid, dist>>
vector<pair<ll, pll>> parents[MAXN];
map<ll, ll> links[MAXN];
ll tot[MAXN];

void predfs(ll pos, ll par){
    sz[pos] = 1;
    for(ll i : adj[pos]){
        if(used[i] || i == par){
            continue;
        }
        predfs(i, pos);
        sz[pos] += sz[i];
    }
}

pll centroid_dfs(ll pos, ll par, ll totsz){
    pll ans = pll(2e9, -1);
    ll maxchild = 0;

    for(ll i : adj[pos]){
        if(used[i] || i == par){
            continue;
        }

        ans = min(ans, centroid_dfs(i, pos, totsz));
        maxchild = max(maxchild, sz[i]);
    }

    ans = min(ans, pll(max(totsz - sz[pos], maxchild), pos));
    return ans;
}

void create_group(ll pos, ll par, ll link, ll centroid, ll prod){
    parents[pos].push_back({centroid, {link, prod}});
    for(ll i : adj[pos]){
        if(used[i] || i == par){
            continue;
        }
        create_group(i, pos, link, centroid, prod * P[pos] % mod);
    }
}

void find_centroid(ll pos){
    predfs(pos, -1);
    ll centroid = centroid_dfs(pos, -1, sz[pos]).second;

    for(ll i : adj[centroid]){
        if(used[i]){
            continue;
        }

        create_group(i, centroid, i, centroid, 1);
    }

    used[centroid] = true;
    for(ll i : adj[centroid]){
        if(used[i]){
            continue;
        }
        find_centroid(i);
    }
}

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1){
            ans = ans * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;
    for(ll a = 1; a <= N; a++){
        cin >> P[a];
    }
    for(ll a = 1; a <= N - 1; a++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_centroid(1);

    while(Q--){
        ll tp;
        cin >> tp;
        if(tp == 1){
            ll s, v;
            cin >> s >> v;

            tot[s] = (tot[s] + v) % mod;
            v = v * P[s] % mod;
            
            for(pair<ll, pll> p : parents[s]){
                ll mult = v * p.second.second % mod;
                tot[p.first] = (tot[p.first] + mult) % mod;
                ll &tmp = links[p.first][p.second.first];
                tmp = (tmp + mult) % mod;
            }
        } else {
            ll s;
            cin >> s;

            ll ans = tot[s];

            for(pair<ll, pll> p : parents[s]){
                ll mult = p.second.second * P[p.first] % mod;
                ans += tot[p.first] * mult % mod;
                ans -= links[p.first][p.second.first] * mult % mod;
                ans %= mod;
                if(ans < 0){
                    ans += mod;
                }
            }

            cout << ans << "\n";
        }
    }
}
