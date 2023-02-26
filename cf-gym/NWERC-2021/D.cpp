#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define x first
#define y second
const int MN = 200005;
int n;
pii a[MN];
int ccw(pii a, pii b, pii c) {
	return (a.y - b.y) * (c.x - b.x) - (c.y - b.y) * (a.x - b.x);
}
int32_t main() {
	cin >> n;
	int mn = 0x3f3f3f3f, mx = -0x3f3f3f3f;
	set<int> ls, rs;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
		mx = max(mx, a[i].x);
		mn = min(mn, a[i].x);
		ls.insert(a[i].x + a[i].y);
		rs.insert(a[i].x - a[i].y);
	}
	if (n == 1) return 0 * printf("4\n");
	if (ls.size() == 1 || rs.size() == 1) return 0 * printf("%lld\n", (mx - mn + 1) * 2 + 3);
	sort(a + 1, a + n + 1);
	int ans = 4;
	vector<pii> top, bot;
	for (int i = 1; i <= n; i++) {
		while (top.size() > 1 && ccw(top[top.size() - 2], top.back(), a[i]) < 0) top.pop_back();
		top.push_back(a[i]);
		while (bot.size() > 1 && ccw(bot[bot.size() - 2], bot.back(), a[i]) > 0) bot.pop_back();
		bot.push_back(a[i]);
	}
	for (int i = 1; i < top.size(); i++) {
		ans += max(abs(top[i].x - top[i - 1].x), abs(top[i].y - top[i - 1].y));
	}
	for (int i = 1; i < bot.size(); i++) {
		ans += max(abs(bot[i].x - bot[i - 1].x), abs(bot[i].y - bot[i - 1].y));
	}
	printf("%lld\n", ans);
}