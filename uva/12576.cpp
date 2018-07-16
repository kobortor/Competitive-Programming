#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const int MAXK = 5;

const ll mod = 7477777;

ll dp[MAXN][MAXK + 1];
ll nck[MAXN][MAXK + 1];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 0; a < MAXN; a++){
        nck[a][0] = 1;
        for(int b = 1; b <= a && b <= MAXK; b++){
            nck[a][b] += (nck[a - 1][b - 1] + nck[a - 1][b]) % mod;
        }
    }

    for(ll b = 1; b <= MAXK; b++){
        ll kcnt = 0;
        ll sqcnt = 0;
        ll totcnt = 0;
        ll dpsum = 0;

        for(ll a = 0; a < MAXN; a++){
            dp[a][b] = totcnt * a * a - 2 * kcnt * a + sqcnt + dpsum;
            dp[a][b] %= mod;
            if(dp[a][b] < 0){
                dp[a][b] += mod;
            }

            ll choose = (a >= 1 && b >= 2) ? nck[a - 1][b - 2] : 0;

            if(a == 0 && b == 1){
                choose = 1;
            }

            kcnt += choose * a;
            sqcnt += choose * a % mod * a;
            totcnt += choose;
            dpsum += dp[a][b - 1];

            kcnt %= mod;
            sqcnt %= mod;
            totcnt %= mod;
            dpsum %= mod;
        }
    }

    int T;
    cin >> T;

    for(int a = 1; a <= T; a++){
        int N;
        cin >> N;
        cout << "Case " << a << ": " << dp[N][MAXK] << "\n";
    }
}
