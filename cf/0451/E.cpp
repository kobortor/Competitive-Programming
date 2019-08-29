#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

ll inv (ll n) {
    ll ans = 1;
    ll power = mod - 2;
    while (power) {
        if (power & 1) ans = ans * n % mod;

        power /= 2;
        n = n * n % mod;
    }

    return ans;
}

ll fact[30];
ll inv_fact[30];

// n <= 20
ll stars_and_bars (ll sum, ll n) {
    ll ans = 1;
    for (ll a = sum + 1; a <= sum + n - 1; a++) 
        ans = ans * (a % mod) % mod;

    return ans * inv_fact [n - 1] % mod;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fact[0] = 1;
    inv_fact[0] = 1;
    for (ll a = 1; a < 30; a++) {
        fact[a] = fact[a - 1] * a % mod;
        inv_fact[a] = inv(fact[a]);
    }

    ll n, s;
    cin >> n >> s;

    vector<ll> f(n);
    for (ll &fi : f) {
        cin >> fi;
    }

    ll ans = 0;
    for (ll state = 0; state < (1ll << n); state++) {
        ll sign = 1;
        ll tot = 0;
        for (ll a = 0; a < n; a++) {
            if (state & (1 << a)) {
                sign *= -1;
                tot += f[a] + 1;
            }
        }

        if (tot <= s) {
            ll tmp = stars_and_bars (s - tot, n);
            ans += sign * tmp;
            ans = (ans % mod + mod) % mod;
        }
    }

    cout << ans;
}
