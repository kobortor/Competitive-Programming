#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	ll N, MINW, MAXW;
	cin >> N >> MINW >> MAXW;

	vector<ll> points(N);
	for (ll &vi : points) {
		cin >> vi;
		vi *= 2;
	}

	sort(allof(points));
	for (int i = 0; i + 1 < N; i++) {
		if (points[i + 1] - points[i] < MINW * 2) {
			cout << "-1\n";
			return 0;
		}
	}

	ll ans = 0;
	ll L_bound = -1e15;
	for (int i = 0; i < N; i++) {
		ll next_pos;
		if (i + 1 < N) {
			next_pos = points[i + 1];
		} else {
			next_pos = 1e15;
		}

		ll x = points[i];
		ll wid = min(x - L_bound, min(MAXW, next_pos - MINW - x));
		ans += wid;
		L_bound = x + wid;
	}
	cout << ans << endl;
}
