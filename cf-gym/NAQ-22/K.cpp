#include "bits/stdc++.h"

using namespace std;
#define ll long long

ll add(ll x, ll y) { return x + y; }
ll sub(ll x, ll y) { return x - y; }
ll mul(ll x, ll y) { return x * y; }
ll dvv(ll x, ll y) {if (y == 0 || (x % y)) return (ll)2e9; return x / y;}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	vector<function<ll(ll,ll)>> op = {
		add, sub, mul, dvv
	};

	ll a, b, c;
	cin >> a >> b >> c;

	ll ans = 2e9;
	for (auto foo : op) {
		for (auto bar : op) {
			ll cv = bar(foo(a, b), c);
			if (cv >= 0) ans = min(ans, cv);
		}
	}

	cout << ans << "\n";

}