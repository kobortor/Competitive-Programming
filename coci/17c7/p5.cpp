#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

int N, M;
int dp[MAXN][2][MAXN];
int req[MAXN];

vector<int> adj[MAXN];

int tmp[2][MAXN];

void dfs(int pos, int par){
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        dfs(i, pos);

        copy(dp[pos][0], dp[pos][0] + MAXN, tmp[0]);
        copy(dp[pos][1], dp[pos][1] + MAXN, tmp[1]);

        for(int a = 0; a <= M; a++){
            for(int b = 0; b <= M; b++){
                int n1 = a + b + 1;
                if(n1 < MAXN){
                    tmp[1][n1] = max(tmp[1][n1], dp[pos][0][a] + max(dp[i][0][b], dp[i][1][b]));
                }

                int n2 = a + b + 2;
                if(n2 < MAXN){
                    tmp[0][n2] = max(tmp[0][n2], dp[pos][0][a] + dp[i][0][b]);
                    tmp[1][n2] = max(tmp[1][n2], dp[pos][1][a] + dp[i][0][b]);
                }
            }
        }
        copy(tmp[0], tmp[0] + MAXN, dp[pos][0]);
        copy(tmp[1], tmp[1] + MAXN, dp[pos][1]);

        for(int a = 1; a <= M; a++){
            dp[pos][0][a] = max(dp[pos][0][a], dp[pos][0][a - 1]);
            dp[pos][1][a] = max(dp[pos][1][a], dp[pos][1][a - 1]);
        }
    }
    for(int a = M; a >= 1; a--){
        dp[pos][0][a] = max(dp[pos][0][a], dp[pos][0][a - 1] + req[pos]);
        dp[pos][1][a] = max(dp[pos][1][a], dp[pos][1][a - 1] + req[pos]);
    }

    for(int a = 1; a <= M; a++){
        dp[pos][0][a] = max(dp[pos][0][a], dp[pos][0][a - 1]);
        dp[pos][1][a] = max(dp[pos][1][a], dp[pos][1][a - 1]);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> req[a];
    }
    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << max(dp[1][0][M], dp[1][1][M]);
}
