#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 51;

int N, M;
unsigned dp[MAXN][MAXN][MAXN][MAXN];
unsigned prefix[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(dp, 0x7f, sizeof dp);

    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            cin >> prefix[a][b];
            prefix[a][b] += prefix[a][b - 1];

            dp[a][b][1][1] = 0;
        }
        for(int b = M; b >= 1; b--){
            prefix[a][b] += prefix[a - 1][b];
        }
    }

    for(int ht = 1; ht <= N; ht++){
        for(int wid = 1; wid <= M; wid++){
            for(int u = 1; u + ht - 1 <= N; u++){
                for(int v = 1; v + wid - 1 <= M; v++){
                    unsigned cost = prefix[u + ht - 1][v + wid - 1] - prefix[u - 1][v + wid - 1] - prefix[u + ht - 1][v - 1] + prefix[u - 1][v - 1];

                    for(int cut = 1; cut < ht; cut++){
                        dp[u][v][ht][wid] = min(dp[u][v][ht][wid], dp[u][v][cut][wid] + dp[u + cut][v][ht - cut][wid] + cost);
                    }

                    for(int cut = 1; cut < wid; cut++){
                        dp[u][v][ht][wid] = min(dp[u][v][ht][wid], dp[u][v][ht][cut] + dp[u][v + cut][ht][wid - cut] + cost);
                    }
                }
            }
        }
    }

    cout << dp[1][1][N][M];
}
