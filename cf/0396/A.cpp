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

vector<int> factorize(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            ans.push_back(i);
        }
    }

    if (n != 1) {
        ans.push_back(n);
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    map<int, int> factors;
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        vector<int> vec = factorize(ai);

        for (int j : vec) {
            factors[j]++;
        }
    }

    ll div = 1;
    for (int i = 1; i <= n - 1; i++) {
        div = div * i % mod;
    }
    div = qpow(div, mod - 2);

    ll ans = 1;
    for (pii p : factors) {
        for (int i = 0; i < n - 1; i++) {
            ans = ans * (p.second - 1 + n - i) % mod;
        }
        ans = ans * div % mod;
    }

    cout << ans;
}
