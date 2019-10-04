#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

vector<ll> primefac (ll x) {
    vector<ll> ans;
    for (ll a = 2; a * a <= x; a++) {
        if (x % a == 0) {
            ans.push_back(a);
            while (x % a == 0) {
                x /= a;
            }
        }
    }

    if (x != 1) {
        ans.push_back(x);
    }

    return ans;
}

ll qpow (ll x, ll y) {
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

    ll x, n;
    cin >> x >> n;

    vector<ll> fac = primefac (x);

    ll ans = 1;

    for (ll p : fac) {
        ll times = 0;
        ll tmp = n;
        while (tmp) {
            times += tmp / p;
            tmp /= p;
        }

        ans = ans * qpow(p, times) % mod;
    }

    cout << ans;
}
