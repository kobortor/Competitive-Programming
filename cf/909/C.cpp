#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
const int MAXN = 5005;

ll dp[MAXN][2];
int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    dp[0][1] = 1;
    for(int a = 0; a < N; a++) {
        char c;
        cin >> c;
        if (c == 's') {
            ll tot = 0;
            for(int b = MAXN - 1; b >= 0; b--){
                tot += dp[b][1];
                tot %= mod;
                dp[b][1] = (tot + dp[b][0]) % mod;
                dp[b][0] = 0;
            }
        } else {
            ll tot = 0;
            for(int b = MAXN - 1; b >= 1; b--) {
                tot += dp[b][1];
                tot %= mod;
                dp[b][0] = (tot + dp[b - 1][0] + dp[b - 1][1]) % mod;
                dp[b][1] = 0;
            }
            dp[0][0] = 0;
            dp[0][1] = 0;
        }
    }

    ll ans = 0;
    for(int a = 0; a < MAXN; a++){
        ans += dp[a][1];
    }
    cout << ans % mod;
}
