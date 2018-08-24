#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
vector<int> adj[MAXN];

//0 - this one is connected
//1 - a child is connected
//2 - need parent to be connected
int dp[MAXN][3];

void dfs(int pos, int par){
    dp[pos][0] = (par != 1);
    dp[pos][1] = 9999999;
    dp[pos][2] = 0;

    int tot1 = 0;
    int best1 = 9999999;
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        dfs(i, pos);

        dp[pos][0] += *min_element(dp[i], dp[i] + 3);

        tot1 += min(dp[i][0], dp[i][1]);
        best1 = min(best1, dp[i][0] - min(dp[i][0], dp[i][1]));
        dp[pos][2] += min(dp[i][0], dp[i][1]);
    }

    dp[pos][1] = tot1 + best1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int i : adj[1]){
        dfs(i, 1);
        ans += dp[i][0];
    }

    cout << ans;
}
