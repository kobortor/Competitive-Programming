#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, Q;

//[pos][owe item][best or 2nd best]
ll dp[MAXN][2][2];
ll cost[MAXN];
vector<int> adj[MAXN];

void merge(int pos, ll res0, ll res1){
    if(res0 > dp[pos][0][0]){
        dp[pos][0][1] = dp[pos][0][0];
        dp[pos][0][0] = res0;
    } else if (res0 > dp[pos][0][1]){
        dp[pos][0][1] = res0;
    }

    if(res1 > dp[pos][1][0]){
        dp[pos][1][1] = dp[pos][1][0];
        dp[pos][1][0] = res1;
    } else if (res1 > dp[pos][1][1]){
        dp[pos][1][1] = res1;
    }
}

void dfs1(int pos, int par){
    dp[pos][0][0] = 0;
    dp[pos][0][1] = -1e16;

    dp[pos][1][0] = cost[pos];
    dp[pos][1][1] = -1e16;

    for(int i : adj[pos]){
        if(i == par) continue;

        dfs1(i, pos);

        merge(pos, max(dp[i][0][0], dp[i][1][0] - cost[pos]), max(dp[i][1][0], dp[i][0][0] + cost[pos]));
    }
}

void dfs2(int pos, int par, pll abv){
    abv = pll(max(abv.first, abv.second - cost[pos]), max(abv.second, abv.first + cost[pos]));
    merge(pos, abv.first, abv.second);

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }

        ll res0 = abv.first;
        if(dp[pos][0][0] == max(dp[i][0][0], dp[i][1][0] - cost[pos])){
            res0 = max(res0, dp[pos][0][1]);
        } else {
            res0 = max(res0, dp[pos][0][0]);
        }

        ll res1 = abv.second;
        if(dp[pos][1][0] == max(dp[i][1][0], dp[i][0][0] + cost[pos])){
            res1 = max(res1, dp[pos][1][1]);
        } else {
            res1 = max(res1, dp[pos][1][0]);
        }

        dfs2(i, pos, pll(res0, res1));
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;
    for(int a = 0; a < N; a++){
        cin >> cost[a];
    }

    for(int a = 0; a < N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0, -1);
    dfs2(0, -1, pll(-1e16, -1e16));

    while(Q--){
        int x;
        cin >> x;
        cout << dp[x][0][0] << "\n";
    }
}
