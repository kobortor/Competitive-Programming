#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) {
        
        int n; cin >> n;

        vector<pair<ll,ll>> bv;
        for (ll i = 0; i < n; i++) {
            ll x; cin >> x;
            bv.push_back({i - x, x});
        }

        sort(bv.begin(), bv.end());

        ll ans = 0;
        while (bv.size()) {
            ll cv = bv.back().first;

            vector<ll> ch;
            while (bv.size() && bv.back().first == cv) {
                ch.push_back(bv.back().second);
                bv.pop_back();
            }

            sort(ch.begin(), ch.end());

            while (ch.size() >= 2) {
                int li = ch.size() - 1;
                if (ch[li] + ch[li - 1] < 0) break;
                ans += ch.back();
                ch.pop_back();
                ans += ch.back();
                ch.pop_back();
            }

        }

        cout << ans << "\n";

    }

}
