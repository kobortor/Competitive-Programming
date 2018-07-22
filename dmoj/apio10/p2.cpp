#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, K;

int ans = 0;
int dp[MAXN][4];

vector<int> adj[MAXN];

void dfs1(int pos, int par){
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }

        dfs1(i, pos);

        int len = dp[i][0] + 1;
        if(len > dp[pos][0]){
            dp[pos][3] = dp[pos][2];
            dp[pos][2] = dp[pos][1];
            dp[pos][1] = dp[pos][0];
            dp[pos][0] = len;
        } else if (len > dp[pos][1]){
            dp[pos][3] = dp[pos][2];
            dp[pos][2] = dp[pos][1];
            dp[pos][1] = len;
        } else if (len > dp[pos][2]){
            dp[pos][3] = dp[pos][2];
            dp[pos][2] = len;
        } else if (len > dp[pos][3]){
            dp[pos][3] = len;
        }
    }
    ans = max(ans, dp[pos][0] + dp[pos][1] - 1);
}

int dfs2(int pos, int par, int abv){
    int best = 0;
    int best2 = 0;
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }

        if(dp[i][0] + 1 == dp[pos][0]){
            int tmp = dfs2(i, pos, max(abv, dp[pos][1]) + 1);
            ans = max(ans, tmp + dp[pos][1] + max(dp[pos][2], abv) - 2);

            if(tmp > best){
                best2 = best;
                best = tmp;
            } else if (tmp > best2){
                best2 = tmp;
            }
        } else if (dp[i][0] + 1 == dp[pos][1]){
            int tmp = dfs2(i, pos, max(abv, dp[pos][0]) + 1);
            ans = max(ans, tmp + dp[pos][0] + max(dp[pos][2], abv) - 2);

            if(tmp > best){
                best2 = best;
                best = tmp;
            } else if (tmp > best2){
                best2 = tmp;
            }
        } else {
            int tmp = dfs2(i, pos, max(abv, dp[pos][0]) + 1);
            ans = max(ans, tmp + dp[pos][0] + max(dp[pos][1], abv) - 2);

            if(tmp > best){
                best2 = best;
                best = tmp;
            } else if (tmp > best2){
                best2 = tmp;
            }
        }
    }

    ans = max(ans, abv + dp[pos][0] + dp[pos][1] + dp[pos][2] + dp[pos][3] - min(abv, dp[pos][3]) - 2);
    ans = max(ans, best + best2 - 2);

    return max(best, dp[pos][0] + dp[pos][1]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1);

    if(K == 2){
        ans = 0;
        dfs2(1, -1, 0);
    }

    cout << 2 * (N - 1) - ans;
}
