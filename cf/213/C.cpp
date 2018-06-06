#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 305;

int N;
int grid[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            cin >> grid[a][b];
        }
    }

    for(int r = 1; r <= N; r++){
        for(int a = 1; a <= N; a++){
            for(int b = 1; b <= N; b++){
                dp[r][a][b] = -1e9;
            }
        }
    }

    dp[1][1][1] = grid[1][1];

    for(int r = 1; r <= N; r++){
        for(int b = 1; b <= N; b++){
            for(int a = 2; a <= N; a++){
                if(a < b){
                    dp[r][a][b] = max(dp[r][a][b], dp[r][a - 1][b] + grid[r][a]);
                } else {
                    dp[r][a][b] = max(dp[r][a][b], dp[r][a - 1][b]);
                }
            }
        }

        for(int a = 1; a <= N; a++){
            for(int b = 2; b <= N; b++){
                dp[r][a][b] = max(dp[r][a][b], dp[r][a][b - 1] + grid[r][b]);
            }
        }

        if(r != N){
            for(int a = 1; a <= N; a++){
                dp[r + 1][a][a] = dp[r][a][a] + grid[r + 1][a];
                for(int b = a + 1; b <= N; b++){
                    dp[r + 1][a][b] = dp[r][a][b] + grid[r + 1][a] + grid[r + 1][b];
                }
            }
        }
    }

    cout << dp[N][N][N];
}
