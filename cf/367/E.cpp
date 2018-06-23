#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 500;
const int MAXM = 1e5 + 5;
const int mod = 1e9 + 7;

int N, M, X;

int ***dp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> X;

    if(N > M){
        cout << 0;
        return 0;
    }

    dp = new int**[M + 1];
    for(int a = 0; a <= M; a++){
        dp[a] = new int*[N + 1];
        for(int b = 0; b <= N; b++){
            dp[a][b] = new int[N + 1];
            fill(dp[a][b], dp[a][b] + N + 1, 0);
        }
    }

    dp[0][0][0] = 1;

    for(int a = 1; a <= M; a++){
        for(int b = 0; b <= N; b++){
            for(int c = 0; c <= b; c++){
                if(b != 0){
                    dp[a][b][c] += dp[a - 1][b - 1][c];
                    dp[a][b][c] %= mod;

                    if(c != 0){
                        dp[a][b][c] += dp[a - 1][b - 1][c - 1];
                        dp[a][b][c] %= mod;
                    }
                }

                if(a != X){
                    dp[a][b][c] += dp[a - 1][b][c];
                    dp[a][b][c] %= mod;

                    if(c != 0){
                        dp[a][b][c] += dp[a - 1][b][c - 1];
                        dp[a][b][c] %= mod;
                    }
                }
            }
        }
    }

    ll ans = dp[M][N][N];
    for(int a = 1; a <= N; a++){
        ans = ans * a % mod;
    }
    cout << ans;
}
