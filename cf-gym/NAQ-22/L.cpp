#include <bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool good(ll x, ll y, ll S) {
    x = abs(x);
    y = abs(y);
    ll minv = min(x, y);
    ll maxv = max(x, y);
    ll twice_cost = 3 * minv + 2 * (maxv - minv);
    // cout << x << ", " << y << " costs " << twice_cost / 2. << endl;
    return twice_cost <= 2 * S;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll T, S;
    cin >> T >> S;

    ll spidey_area = 0;
    ll taxi_area = 0;

    for (ll x = -S; x <= S; x++) {
        ll lo = 0, hi = 1e7;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (good(x, mid, S)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        ll spidey_height = hi;
        spidey_area += 2 * spidey_height + 1;

        if (abs(x) <= T) {
            ll taxi_reach = min(spidey_height, T - abs(x));
            taxi_area += 2 * taxi_reach + 1;
        }
    }

	if (taxi_area == 0) {
		cout << 0 << "\n";
	} else if (taxi_area == spidey_area) {
		cout << 1 << "\n";
	} else {
		ll g = __gcd(taxi_area, spidey_area);
		taxi_area /= g;
		spidey_area /= g;
    	cout << taxi_area << "/" << spidey_area << "\n" << endl;
	}
}
