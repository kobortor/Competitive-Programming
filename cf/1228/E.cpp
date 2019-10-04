#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 255;
const ll mod = 1e9 + 7;

ll dp[MAXN][MAXN];
ll nck[MAXN][MAXN];

ll kpow[MAXN];
ll ksub1pow[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    nck[0][0] = 1;
    for (int a = 1; a < MAXN; a++) {
        nck[a][0] = 1;
        for (int b = 1; b <= a; b++) {
            nck[a][b] = (nck[a - 1][b - 1] + nck[a - 1][b]) % mod;
        }
    }

    ll n, k;
    cin >> n >> k;

    kpow[0] = 1;
    ksub1pow[0] = 1;
    for (int a = 1; a < MAXN; a++) {
        kpow[a] = kpow[a - 1] * k % mod;
        ksub1pow[a] = ksub1pow[a - 1] * (k - 1) % mod;
    }

    dp[0][0] = 1;

    for (int a = 1; a <= n; a++) {          // row id
        for (int b = 1; b <= n; b++) {      // number of columns with 1
            for (int c = 0; c < b; c++) {   // number of columns with 1 before
                ll toadd = dp[a - 1][c] * nck[n - c][b - c] % mod * ksub1pow[n - b] % mod * kpow[c] % mod;
                dp[a][b] = (dp[a][b] + toadd) % mod;
            }

            // make sure we are doing at least 1 on this row
            ll toadd = dp[a - 1][b] * ksub1pow[n - b] % mod * (kpow[b] - ksub1pow[b] + mod) % mod;
            dp[a][b] = (dp[a][b] + toadd) % mod;
        }
    }

    cout << dp[n][n];
}
