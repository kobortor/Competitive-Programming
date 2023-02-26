#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MN = 1000005;
double fpow(double b, int p) {
	if (!p) return 1;
	double ret = fpow(b, p / 2);
	if (p & 1) return ret * ret * b;
	return ret * ret;
}
int32_t main() {
	int n, p, k;
	cin >> n >> p >> k;
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i < p) {
			double all = fpow((p - 1) * 1.0 / n, k);
			ans += all * 1.0 + (1 - all) * 0.5;
		} else if (i > p) {
			double all = fpow((i - 1) * 1.0 / n, k);
			ans += (1 - all) * 0.5;
		}
	}
	printf("%.8f\n", 1 + ans);
}