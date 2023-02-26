#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define pii pair<int, int>
#define f first
#define s second

const int MN = 105;

int n, a[MN], dp[MN][MN];

int rec(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	int val = __gcd(a[l], a[r]);
	if ((l + 1) % n == r) return dp[l][r] = 0;
	dp[l][r] = 0x3f3f3f3f;
	if (l < r) {
		for (int i = l + 1; i < r; i++) dp[l][r] = min(dp[l][r], rec(l, i) + rec(i, r) + val);
	} else {
		for (int i = l + 1; i < n; i++) dp[l][r] = min(dp[l][r], rec(l, i) + rec(i, r) + val);
		for (int i = 0; i < r; i++) dp[l][r] = min(dp[l][r], rec(l, i) + rec(i, r) + val);
	}
	return dp[l][r];
}

int32_t main() {
	while (1) {
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; i++) cin >> a[i];
		memset(dp, -1, sizeof(dp));
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = min(ans, rec(i, j) + rec(j, i) + __gcd(a[i], a[j]));
			}
		}
		printf("%lld\n", ans);
	}
}