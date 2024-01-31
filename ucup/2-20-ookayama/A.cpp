#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;
    cin >> n;

    ll ans = 0;

    ll pow2 = 1;
    for (int i = 0; i < n; i++) {
        ans += pow2;
        ans %= mod;
        pow2 *= 2;
        pow2 %= mod;
    }

    ans = (ans - n + mod) % mod;
    cout << ans << endl;
}
