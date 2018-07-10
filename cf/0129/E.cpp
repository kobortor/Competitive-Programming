#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

const int MAXN = 1005;

ll dp[MAXN];
ll tmp[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M, K;
    
    cin >> N >> M >> K;

    fill(dp + 1, dp + MAXN, 1);

    while(K--){
        ll tot = 0;
        ll accum = 0;
        for(int a = 1; a < MAXN; a++){
            if(a != 1){
                accum += dp[a - 2];
                tot += accum;
                
                accum %= mod;
                tot %= mod;
            }
            tmp[a] = tot;
        }
        memcpy(dp, tmp, sizeof dp);
    }

    cout << dp[N] * dp[M] % mod;
}
