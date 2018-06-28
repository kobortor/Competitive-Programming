#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;

int dp[MAXN][2];
vector<int> adj[MAXN];

void dfs(int pos, int par){
    int bestodd = 0;
    int besteven = -9999999;
    for(int i : adj[pos]){
        if (i == par){
            continue;
        }

        dfs(i, pos);

        int odd1 = max(bestodd + dp[i][0] + 1, besteven + dp[i][1]);
        int even1 = max(besteven + dp[i][0] + 1, bestodd + dp[i][1]);

        bestodd = odd1;
        besteven = even1;
    }
    dp[pos][0] = besteven;
    dp[pos][1] = bestodd;
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

    dfs(1, -1);
    if(dp[1][0] < 0){
        cout << -1;
    } else {
        cout << dp[1][0];
    }
}
