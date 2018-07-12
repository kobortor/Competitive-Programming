#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

const ll mod = 1e9 + 7;

int N, K;

vector<int> adj[MAXN];
int color[MAXN];
int dp[MAXN][3];

void dfs(int pos, int par){
    vector<ll> ans(8), tmp(8);
    ans[0] = 1;

    for(int i : adj[pos]){
        fill(allof(tmp), 0);
        if(i == par){
            continue;
        }

        dfs(i, pos);

        for(int a = 0; a < 8; a++){
            for(int b = 0; b < 3; b++){
                tmp[a | (1 << b)] += ans[a] * dp[i][b];
                tmp[a | (1 << b)] %= mod;
            }
        }

        copy(allof(tmp), ans.begin());
    }

    if(color[pos] == 0){
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 8; b++){
                if((1 << a) & b){
                    continue;
                }

                dp[pos][a] += ans[b];
                dp[pos][a] %= mod;
            }
        }
    } else {
        int a = color[pos] - 1;
        for(int b = 0; b < 8; b++){
            if((1 << a) & b){
                continue;
            }

            dp[pos][a] += ans[b];
            dp[pos][a] %= mod;
        }
    }

}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    cin >> N >> K;

    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(K--){
        int pos;
        cin >> pos;
        cin >> color[pos];
    }

    dfs(1, -1);

    int ans = 0;
    for(int a = 0; a < 3; a++){
        ans = (ans + dp[1][a]) % mod;
    }

    cout << ans;
}
