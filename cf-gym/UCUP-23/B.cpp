#include <bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<ll, ll> pll;

pll operator-(pll p1, pll p2) {
	return {p1.first - p2.first, p1.second - p2.second};
}

ll cross(pll p1, pll p2) {
	return p1.first * p2.second - p1.second * p2.first;
}

ll norm(pll p) {
	return p.first * p.first + p.second * p.second;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int z;
    cin >> z;

    while (z--) {
		int n;
		cin >> n;

		vector<pll> pts;
		pts.push_back({1, 0});
		pts.push_back({n, 0});
		for (int i = 1; i <= n; i++) {
			ll y;
			cin >> y;
			pts.push_back({i, y});
		}
		iter_swap(pts.begin(), min_element(allof(pts)));
		pll p0 = pts[0];
		sort(pts.begin() + 1, pts.end(), [=](pll p1, pll p2) {
			p1 = p1 - p0;
			p2 = p2 - p0;
			ll cx = cross(p1, p2);
			if (cx == 0) {
				// longest first
				return norm(p1) > norm(p2);
			} else {
				return cx < 0;
			}
		});
		// for (pll p : pts) {
		// 	cout << p.first << " " << p.second << endl;
		// }

		vector<pll> hull;
		hull.push_back(pts[0]);
		for (int i = 1; i < (int)pts.size(); i++) {
			// ignore same directions
			if (i != 1 && cross(pts[i - 1] - pts[0], pts[i] - pts[0]) == 0) {
				continue;
			}
			while ((int)hull.size() >= 2) {
				int m = hull.size();
				if (cross(hull[m - 2] - hull[m - 1], pts[i] - hull[m - 1]) < 0) {
					hull.pop_back();
				} else {
					break;
				}
			}
			hull.push_back(pts[i]);
		}

		ll ans = 0;
		for (int i = 1; i + 2 < (int)hull.size(); i++) {
			ll x1 = hull[i].first;
			ll x2 = hull[i + 1].first;
			ll y1 = hull[i].second;
			ll y2 = hull[i + 1].second;
			ans += (x2 - x1) * (y1 + y2);
		}
		cout << ans << "\n";
    }
}
