#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const int MAXK = 102;

ll N, A, B, C;
ll dp[MAXN][MAXK];
ll targ[MAXN];

ll sq(ll x){
    return x * x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B >> C;
    for(int a = 1; a <= N; a++){
        cin >> targ[a];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int a = 1; a <= N; a++){
        ll best = 1e18;
        for(int b = 0; b <= 100; b++){
            best = min(best, dp[a - 1][b] - b * B);
            dp[a][b] = best + C * sq(targ[a] - b) + b * A + b * B;
        }

        best = 1e18;
        for(int b = 100; b >= 0; b--){
            best = min(best, dp[a - 1][b]);
            dp[a][b] = min(dp[a][b], best + C * sq(targ[a] - b) + b * A);
        }
    }

    ll ans = 1e18;
    for(int a = 0; a <= 100; a++){
        ans = min(ans, dp[N][a]);
    }
    cout << ans;
}
