#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define pii pair<int, int>
#define f first
#define s second

int32_t main() {
	string s;
	cin >> s;
	int n = s.size();
	int ans = n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int len = j - i + 1;
			int p = i;
			int tmp = n;
			for (int k = 0; k < n; k++) {
				bool ok = 1;
				for (int l = 0; l < len; l++) {
					if (s[k + l] != s[p + l]) ok = 0;
				}
				if (ok) k += len - 1, tmp -= len - 1;
			}
			ans = min(ans, tmp + len);
		}
	}
	printf("%lld\n", ans);
}