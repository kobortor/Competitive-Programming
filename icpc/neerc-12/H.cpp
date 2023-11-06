#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("hyperdrome.in", "r", stdin);
    freopen("hyperdrome.out", "w", stdout);

    ll n; cin >> n;

    string s; cin >> s;

    map<ll,ll> cnt;
    cnt[0]++;

    ll ans = 0;
    ll sf = 0;

    for (int i = 0; i < n; i++) {
        
        int cv = (('a' <= s[i] && s[i] <= 'z') ?
                     (s[i] - 'a') :
                     (s[i] - 'A') + 26);

        sf ^= (1ll << cv);
        
        ans += cnt[sf];

        for (int j = 0; j < 52; j++) {
            ll goal = sf ^ (1ll << j);
            if (cnt.find(goal) != cnt.end())
                ans += cnt[goal];
        }

        cnt[sf]++;

    }

    cout << ans << "\n";

}
