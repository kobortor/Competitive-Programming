#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
ll choc[MAXN];
vector<int> adj[MAXN];

ll dp[MAXN][3];

void dfs1(int pos, int par){
    for(int i : adj[pos]){
        if(i == par) continue;
        dfs1(i, pos);
        ll val = dp[i][0] + choc[i];
        if(val > dp[pos][0]){
            dp[pos][2] = dp[pos][1];
            dp[pos][1] = dp[pos][0];
            dp[pos][0] = val;
        } else if (val > dp[pos][1]) {
            dp[pos][2] = dp[pos][1];
            dp[pos][1] = val;
        } else if (val > dp[pos][2]) {
            dp[pos][2] = val;
        }
    }
}

ll ans = 0;
ll dfs2(int pos, int par, ll parlen){
    ll b1 = 0, b2 = 0;
    for(int i : adj[pos]){
        if(i == par) continue;

        ll val;
        if(dp[i][0] + choc[i] == dp[pos][0]){
            val = dfs2(i, pos, max(parlen, dp[pos][1]) + choc[pos]);
        } else {
            val = dfs2(i, pos, max(parlen, dp[pos][0]) + choc[pos]);
        }

        if(val > b1){
            b2 = b1;
            b1 = val;
        } else if (val > b2) {
            b2 = val;
        }

        if(dp[i][0] + choc[i] == dp[pos][0]){
            ans = max(ans, val + dp[pos][1] + max(parlen, dp[pos][2]) + choc[pos]);
        } else if (dp[i][0] + choc[i] == dp[pos][1]) {
            ans = max(ans, val + dp[pos][0] + max(parlen, dp[pos][2]) + choc[pos]);
        } else {
            ans = max(ans, val + dp[pos][0] + max(parlen, dp[pos][1]) + choc[pos]);
        }
    }
    ans = max(ans, b1 + b2);
    return max(b1, choc[pos] + dp[pos][0] + dp[pos][1]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> choc[a];
    }
    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1, 0);
    cout << ans;
}
