#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// gets length of 1 12 123 ... (123...k)
ll checklen (ll k) {
    ll ans = 0;
    ll p10 = 1;
    ll dig = 1;
    while (p10 <= k) {
        // number of things with this many digits
        ll num = min(9 * p10, k - p10 + 1);

        ans += (k + 1) * num * dig;
        ans -= (num + 2 * p10 - 1) * num / 2 * dig;

        dig++;
        p10 = p10 * 10;
    }

    return ans;
}

// gets length of (123..k)
ll singlelen (ll k) {
    ll ans = 0;
    ll p10 = 1;
    ll dig = 1;
    while (p10 <= k) {
        // number of things with this many digits
        ll num = min(9 * p10, k - p10 + 1);

        ans += num * dig;

        dig++;
        p10 = p10 * 10;
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        ll x;
        cin >> x;

        ll lo = 0, hi = 2e9;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (checklen(mid) >= x) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        ll offset = checklen(hi);

        lo = 0, hi = 2e9;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (singlelen(mid) >= x - offset) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        ll offset2 = singlelen(hi);
        ll num = hi + 1;
        string s = to_string(num);

        cout << s[x - offset - offset2 - 1] << "\n";
    }
}
