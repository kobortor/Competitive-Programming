#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e6 + 6;
const ll mod = 1e9 + 7;

ll fact[MAXN];

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}

ll nck(ll n, ll k){
    return fact[n] * qpow(fact[k], mod - 2) % mod * qpow(fact[n - k], mod - 2) % mod;
}

int Q;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fact[0] = 1;
    for(int a = 1; a < MAXN; a++){
        fact[a] = fact[a - 1] * a % mod;
    }

    cin >> Q;

    while(Q--){
        int xi, yi;
        cin >> xi >> yi;

        vector<int> factors;

        for(int a = 2; a * a <= xi; a++){
            if(xi % a == 0){
                int tmp = 0;
                while(xi % a == 0){
                    xi /= a;
                    tmp++;
                }
                factors.push_back(tmp);
            }
        }

        if(xi != 1){
            factors.push_back(1);
        }

        ll ans = qpow(2, yi - 1);
        for(int i : factors){
            ans = ans * nck(yi + i - 1, yi - 1) % mod;
        }
        cout << ans << "\n";
    }
}
