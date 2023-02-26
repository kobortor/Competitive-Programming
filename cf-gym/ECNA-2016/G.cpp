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

vector<int> st, ed, mid;

int rec(int n) {
	if (n == 0) return 0;
	int ret = 0;
	if (st.size() && st.back() == n) {
		ret += 1ll << (n - 1);
		st.pop_back();
		swap(mid, ed);
		ret += rec(n - 1);
	} else if (ed.size() && ed.back() == n) {
		ed.pop_back();
		swap(st, mid);
		ret += rec(n - 1);
	} else {
		printf("No\n");
		exit(0);
	}
	return ret;
}

int32_t main() {
	int k, n = 0, u;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> u;
		st.push_back(u);
		n = max(n, u);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> u;
		mid.push_back(u);
		n = max(n, u);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> u;
		ed.push_back(u);
		n = max(n, u);
	}
	reverse(st.begin(), st.end());
	reverse(mid.begin(), mid.end());
	reverse(ed.begin(), ed.end());
	printf("%lld\n", rec(n));
}