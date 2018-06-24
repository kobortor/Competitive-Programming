#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
ll dp[MAXN][2];

void dfs(int pos, int par){
    ll sum0 = 0, sum1 = 0;

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }

        dfs(i, pos);

        sum0 += dp[i][0];
        sum1 += dp[i][1];
    }

    dp[pos][0] = sum1 + 1;
    dp[pos][1] = min(dp[pos][0], sum0);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    cout << dp[1][1] << "\n";
}
