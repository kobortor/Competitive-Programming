#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

const ll mod = 1e9 + 7;

int N;
ll val[MAXN];

ll sz[MAXN][2];
vector<int> adj[MAXN];

void dfs1(int pos, int par){
    sz[pos][0] = 1;
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        dfs1(i, pos);

        sz[pos][0] += sz[i][1];
        sz[pos][1] += sz[i][0];
    }
}

ll ans = 0;

void dfs2(int pos, int par, ll s0, ll s1){
    ans += s0 * sz[pos][0] % mod * val[pos] % mod;
    ans -= s1 * sz[pos][1] % mod * val[pos] % mod;
    ans += (s0 + sz[pos][0] - 1) * val[pos] % mod;
    ans %= mod;
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        ans += (sz[pos][0] - sz[i][1] + s0) * sz[i][1] % mod * val[pos] % mod;
        ans -= (sz[pos][1] - sz[i][0] + s1) * sz[i][0] % mod * val[pos] % mod;
        ans %= mod;

        dfs2(i, pos, s1 + sz[pos][1] - sz[i][0], s0 + sz[pos][0] - sz[i][1]);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> val[a];
    }

    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1, 0, 0);
    for(int a = 1; a <= N; a++){
        ans += val[a];
    }
    ans %= mod;
    if(ans < 0){
        ans += mod;
    }
    cout << ans;
}
