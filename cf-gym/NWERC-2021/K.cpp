#include "bits/stdc++.h"

using namespace std;

int main() {

	int n; cin >> n;
	map<string,int> tv;

	vector<array<int,3>> cnt;

	for (int i = 0; i < n; i++) {
		string ty, side; int cv;
		cin >> ty >> side >> cv;
		int ind;

		if (tv.find(ty) != tv.end()) ind = tv[ty];
		else {
			ind = cnt.size();
			tv[ty] = ind;
			cnt.push_back({0, 0, 0});
		}

		if (side == "left") cnt[ind][0] += cv;
		else if (side == "right") cnt[ind][1] += cv;
		else cnt[ind][2] += cv;
	}

	int ans = 0;
	int good = 0;
	for (auto [l, r, any] : cnt) {

		int tot = l + r + any;
		if (tot <= 1) {
			ans += tot;
			continue;
		}

		if (max(l, r) == 0) {
			ans++;

			if (any > 1) good = 1;

			continue;
		}
		
		ans += max(l, r);
		
		if (any > 0 || min(l, r) > 0) good = 1;

	}

	if (!good) {
		cout << "impossible\n";
	}
	else {
		cout << ans + 1 << "\n";
	}

}