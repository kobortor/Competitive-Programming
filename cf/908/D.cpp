#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
const ll mod = 1e9 + 7;

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1){
            ans = ans * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

ll inv(ll x){
    return qpow(x, mod - 2);
}

ll frac(ll x, ll y){
    return x * inv(y) % mod;
}

ll K;
ll PA, PB;
ll chanceA, chanceB;

//[num A][num AB]
ll dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> K >> PA >> PB;
    chanceA = frac(PA, PA + PB);
    chanceB = frac(PB, PA + PB);

    dp[0][0] = 1;

    for(int a = 1; a <= K; a++){
        for(int b = 0; b < K; b++){
            dp[a][b] = dp[a - 1][b] * chanceA;
            if(b >= a){
                dp[a][b] += dp[a][b - a] * chanceB;
            }
            dp[a][b] %= mod;
            if(a == 1 && b == 0){
                dp[a][b] = 1;
            }
        }
    }

    ll ans = 0;
    for(int a = 1; a < K; a++){
        for(int b = K - a; b < K; b++){
            //a + b >= K
            ans += (a + b) * chanceB % mod * dp[a][b];
            ans %= mod;
        }
    }
    for(int b = 0; b < K; b++){
        ans += chanceB * dp[K][b] % mod * frac(chanceA, (chanceA - 1) * (chanceA - 1) % mod);
        ans %= mod;

        ans += (b + K) * chanceB % mod * dp[K][b] % mod * -frac(1, chanceA - 1);
        ans %= mod;
        if(ans < 0){
            ans += mod;
        }
    }
    cout << ans;
}