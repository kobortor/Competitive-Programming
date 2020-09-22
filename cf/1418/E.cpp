#include<bits/stdc++.h>

// Created by kobortor On 11:49:33 on 22-09-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

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

ll inv(ll x) {
    return qpow(x, mod - 2);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> d(n);
    for (int &di : d) cin >> di;

    sort(allof(d));

    // id, a, b
    vector<tuple<int, int, int>> shields(m);
    for (int i = 0; i < m; i++) {
        get<0>(shields[i]) = i;
        cin >> get<1>(shields[i]) >> get<2>(shields[i]);
    }

    // sort by b
    sort(allof(shields), [](auto x, auto y){ return get<2>(x) < get<2>(y); });

    int lft_d = 0, rht_d = accumulate(allof(d), 0ll) % mod;

    vector<int> ans(n);
    for (int i = 0, j = 0; i < m; i++) {
        auto [idx, a, b] = shields[i];
        while (j < n && d[j] < b) {
            lft_d = (lft_d + d[j]) % mod;
            rht_d = (rht_d + mod - d[j]) % mod;
            j++;
        }
        
        int k = n - j;
        if (k > a) {
            ans[idx] = (ans[idx] + (k - a) * inv(k) % mod * rht_d) % mod;
        }

        if (k + 1 > a) {
            ans[idx] = (ans[idx] + (k + 1 - a) * inv(k + 1) % mod * lft_d) % mod;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
}
