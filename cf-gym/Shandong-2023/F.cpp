#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1000000007;

ll solve(vector<pair<ll,ll>> v) {

    vector<ll> disc = {-1};
    for (auto [x, y] : v) {
        disc.push_back(x);
        disc.push_back(y);
    }

    sort(disc.begin(), disc.end());
    disc.resize(unique(disc.begin(), disc.end()) - disc.begin());
    
    vector<vector<int>> ep(disc.size());

    for (auto &[x, y] : v) {
        x = lower_bound(disc.begin(), disc.end(), x) - disc.begin();
        y = lower_bound(disc.begin(), disc.end(), y) - disc.begin();
        ep[y].push_back(x);
    }

    vector<ll> dp(disc.size());
    dp[0] = 1;

    for (int i = 1; i < disc.size(); i++) {
        dp[i] = dp[i - 1];
        for (int x : ep[i]) {
            dp[i] += dp[x - 1];
            dp[i] %= MOD;
        }
    }

    return dp.back();

}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) {
        
        int n; cin >> n;

        vector<vector<pair<ll,ll>>> seg(n);
        for (int i = 0; i < n; i++) {
            ll l, r, x; cin >> l >> r >> x;
            seg[x - 1].push_back({l, r});
        }

        ll ans = 1;
        for (auto v : seg) {
            ans *= solve(v);
            ans %= MOD;
        }

        cout << ans << "\n";

    }

}
