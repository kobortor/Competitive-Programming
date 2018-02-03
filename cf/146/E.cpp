#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const int MAXL = 1030;
const ll mod = 1e9 + 7;

int N, K;

ll unlucky;

ll cnt[MAXL];
vector<ll> lucky;

ll dp[MAXL];

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

ll fact[MAXN];

ll nck(ll n, ll k){
    return fact[n] * qpow(fact[k], mod - 2) % mod * qpow(fact[n - k], mod - 2) % mod;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fact[0] = 1;
    for(int a = 1; a < MAXN; a++){
        fact[a] = fact[a - 1] * a % mod;
    }

    for(int n = 1; n < 10; n++){
        for(int a = 0; a < (1 << n); a++){
            int num = 0;
            for(int b = 0; b < n; b++){
                if(a & (1 << b)){
                    num = num * 10 + 4;
                } else {
                    num = num * 10 + 7;
                }
            }
            lucky.push_back(num);
        }
    }
    sort(allof(lucky));

    cin >> N >> K;
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        auto iter = lower_bound(allof(lucky), x);

        if(iter == lucky.end() || *iter != x){
            unlucky++;
        } else {
            cnt[iter - lucky.begin()]++;
        }
    }
    
    dp[0] = 1;
    for(int a = 0; a < (int)lucky.size(); a++){
        for(int b = a; b >= 0; b--){
            dp[b + 1] += dp[b] * cnt[a];
            dp[b + 1] %= mod;
        }
    }

    ll ans = 0;
    for(int a = 0; a <= min(K, (int)lucky.size()); a++){
        if(0 <= K - a && K - a <= unlucky){
            ans += dp[a] * nck(unlucky, K - a);
            ans %= mod;
        }
    }
    cout << ans;
}
