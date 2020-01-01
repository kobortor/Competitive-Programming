#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

ll qpow(ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1) {
            ans = ans * x % mod;
        }

        x = x * x % mod;
        y >>= 1;
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    ll k;

    cin >> s >> k;

    ll num = (1 - qpow(2, s.size() * k) + mod) % mod;
    ll dem = (1 - qpow(2, s.size()) + mod) % mod;

    ll prod = num * qpow(dem, mod - 2) % mod;

    ll tot = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '0' || s[i] == '5') {
            tot = (tot + qpow(2, i)) % mod;
        }
    }

    cout << tot * prod % mod;
}
