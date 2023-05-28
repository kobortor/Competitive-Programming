#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define allof(x) (x).begin(), (x).end()

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;

        vector<pll> v(n);
        for (pll &p : v) {
            cin >> p.first >> p.second;
        }

        sort(allof(v));
        ll avail = 0;
        ll used = 0;
        bool ans = true;
        for (pll p : v) {
            avail = p.first * k;
            used += p.second;
            if (used > avail) {
                ans = false;
            }
        }
        cout << (ans ? "Yes\n" : "No\n");
    }
}
