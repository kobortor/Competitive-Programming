#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e8;

const int MAXN = 101;
const int MAXK = 11;

//[total][num N1][last type][number of last type]
int dp[2 * MAXN][MAXN][2][MAXK];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N1, N2, K1, K2;
    cin >> N1 >> N2 >> K1 >> K2;

    dp[0][0][0][0] = 1;
    for(int a = 0; a < N1 + N2; a++){
        for(int b = 0; b <= a && b <= N1; b++){
            //tp1
            for(int k = 0; k <= K1; k++){
                //add tp1
                if(b + 1 <= N1 && k + 1 <= K1){
                    dp[a + 1][b + 1][0][k + 1] += dp[a][b][0][k];
                    dp[a + 1][b + 1][0][k + 1] %= mod;
                }

                //add tp2
                if(a - b + 1 <= N2){
                    dp[a + 1][b][1][1] += dp[a][b][0][k];
                    dp[a + 1][b][1][1] %= mod;
                }
            }

            //tp2
            for(int k = 0; k <= K2; k++){
                //add tp1
                if(b + 1 <= N1){
                    dp[a + 1][b + 1][0][1] += dp[a][b][1][k];
                    dp[a + 1][b + 1][0][1] %= mod;
                }

                //add tp2
                if(a - b + 1 <= N2 && k + 1 <= K2){
                    dp[a + 1][b][1][k + 1] += dp[a][b][1][k];
                    dp[a + 1][b][1][k + 1] %= mod;
                }
            }
        }
    }

    int ans = 0;
    for(int k = 0; k <= K1; k++){
        ans += dp[N1 + N2][N1][0][k];
        ans %= mod;
    }

    for(int k = 0; k <= K2; k++){
        ans += dp[N1 + N2][N1][1][k];
        ans %= mod;
    }
    cout << ans;
}
