#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const ll MAXN = 3e5 + 5;

ll N, A, B, K;
ll fact[MAXN];

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1){
            ans = ans * x % mod;
        }

        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}

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

    cin >> N >> A >> B >> K;

    ll ans = 0;
    for(int a = 0; a <= N; a++){
        ll remain = K - a * A;
        if(remain % B != 0){
            continue;
        }
        ll numB = remain / B;
        if(numB < 0 || numB > N){
            continue;
        }

        ll tmp = nck(N, a) * nck(N, numB) % mod;
        ans += tmp;
        ans %= mod;
    }
    cout << ans;
}
