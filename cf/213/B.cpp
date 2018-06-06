#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
const int MAXN = 105;

ll N;
ll pascal[MAXN][MAXN];
ll cnt[10];
ll dp[MAXN][10];

ll solve(ll sz, ll id){
    if(id == 10){
        return sz == 0;
    }

    if(dp[sz][id] != -1){
        return dp[sz][id];
    }

    ll ans = 0;
    if(id == 0){
        for (ll i = cnt[0]; i <= sz; i++){
            ans += solve(sz - i, 1) * (pascal[sz][i] - (i == 0 ? 0 : pascal[sz - 1][i - 1]));
            ans %= mod;
            if(ans < 0){
                ans += mod;
            }
        }
    } else {
        for (ll i = cnt[id]; i <= sz; i++){
            ans += solve(sz - i, id + 1) * pascal[sz][i];
            ans %= mod;
            if(ans < 0){
                ans += mod;
            }
        }
    }

    return dp[sz][id] = ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(dp, -1, sizeof dp);

    pascal[0][0] = 1;
    for(int a = 1; a < MAXN; a++){
        for(int b = 1; b < MAXN; b++){
            pascal[a][b] = (pascal[a - 1][b - 1] + pascal[a - 1][b]) % mod;
        }
        pascal[a][0] = 1;
    }

    cin >> N;
    for(int a = 0; a < 10; a++){
        cin >> cnt[a];
    }

    ll ans = 0;
    for(int n = 1; n <= N; n++){
        ans += solve(n, 0);
        ans %= mod;
    }
    cout << ans;
}
