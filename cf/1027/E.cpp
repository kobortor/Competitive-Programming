#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;
const ll mod = 998244353;

ll N, K;

ll dp[MAXN][MAXN];

ll presolve(int maxlen){
    dp[1][1] = 1;
    for(int a = 2; a <= N; a++){
        ll tot = 0;
        for(int b = 1; b <= maxlen; b++){
            tot += dp[a - 1][b - 1];

            dp[a][b] = dp[a - 1][b - 1];
        }

        dp[a][1] += tot + dp[a - 1][maxlen];
        dp[a][1] %= mod;
    }

    ll ans = 0;
    for(int a = 1; a <= maxlen; a++){
        ans += dp[N][a];
        ans %= mod;
    }

    ans %= mod;
    return ans;
}

ll limit[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    for(int a = 1; a <= N; a++){
        limit[a] = presolve(a);
    }

    for(int a = N; a >= 1; a--){
        limit[a] = (limit[a] - limit[a - 1] + mod) % mod;
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            if(a * b < K){
                ans += limit[a] * limit[b];
                ans %= mod;
            }
        }
    }

    cout << (ans * 2) % mod;
}
