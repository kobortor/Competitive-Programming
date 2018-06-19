#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

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

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll x, k;
    cin >> x >> k;

    if(x == 0){
        cout << 0;
    } else {
        x %= mod;
        cout << (x * qpow(2, k + 1) - qpow(2, k) + 1 + mod) % mod;
    }
}
