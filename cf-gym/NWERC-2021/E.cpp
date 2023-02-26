#include "bits/stdc++.h"

using namespace std;
#define ll long long
// #define DEBUG
const int MAXN = 300300;

#ifdef DEBUG
const int THRS = 10;
#endif
#ifndef DEBUG
const int THRS = 200000;
#endif

struct Fenwick
{
	
	int n;
	vector<int> bit;

	Fenwick(int _n) {
		n = _n;
		bit = vector<int>(n + 5);
	}

	void update(int ind, int v) {
		ind += 2;
		while (ind < n + 5) {
			bit[ind] += v;
			ind += (ind & (-ind));
		}
	}

	int query(int ind) {
		int ans = 0;
		ind += 2;
		while (ind > 0) {
			ans += bit[ind];
			ind -= (ind & (-ind));
		}
		return ans;
	}

};

// students by height
set<int> sbh[MAXN];
vector<int> bv[MAXN];

void construct(vector<int> a, vector<int> b) {

	vector<pair<int,int>> ans;
	int n = a.size();

	auto output = [&]() {

		for (auto [x, y] : ans)
			cout << x << " " << y << "\n";
		exit(0);

	};

	set<int> curr;
	for (int i = 0; i < n; i++) {
		curr.insert(i);
		bv[b[i]].push_back(i);
		sbh[a[i]].insert(i);
	}

	for (int i = 0; i < n; i++)
		reverse(bv[i].begin(), bv[i].end());

	vector<int> goal; // index we want each thing to end up at

	for (int i = 0; i < n; i++) {
		int cv = a[i];
		goal.push_back(bv[cv].back());
		bv[cv].pop_back();
	}

	auto swap_it = [&](int x, int y) {

		int xv = a[x], yv = a[y];
		sbh[xv].erase(x);
		sbh[yv].erase(y);
		sbh[xv].insert(y);
		sbh[yv].insert(x);

		swap(goal[x], goal[y]);
		swap(a[x], a[y]);

		ans.push_back({x + 1, y + 1});

		if (ans.size() >= THRS) {
			output();
		}
	};

	for (int i = 0; i < n; i++) {
		if (!sbh[i].size()) continue;

		int it = *sbh[i].begin();
		while (sbh[i].size()) {

			// cout << "at " << i << " " << it << endl;

			if (goal[it] == it) {
				if (it == *sbh[i].begin()) {
					sbh[i].erase(it);
					curr.erase(it);
					if (sbh[i].size()) it = *sbh[i].begin();
				}
				else {
					auto ni = sbh[i].lower_bound(it);
					ni--;
					int nv = *ni;
					sbh[i].erase(it);
					curr.erase(it);
					it = nv;
				}
			}
			else {

				if (it > goal[it]) {
					auto pit = curr.lower_bound(it); pit--;
					int pi = *pit;
					swap_it(pi, it);
					it = pi;
					continue;
				}

				int ni = *curr.upper_bound(it);
				if (sbh[i].count(ni)) {
					it = ni;
				}
				else {
					swap_it(it, ni);
					it = ni;
				}
			}

		}

	}

	output();

}

ll numerical(vector<int> a, vector<int> b) {

	int n = a.size();
	vector<vector<int>> indbv(n);
	vector<vector<int>> indav(n);

	for (int i = 0; i < n; i++) {
		indbv[b[i]].push_back(i);
		indav[a[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		reverse(indbv[i].begin(), indbv[i].end());
	}

	vector<int> goal(n);
	vector<int> bprime(n), aprime(n);

	Fenwick helper(n + 3);
	for (int i = n - 1; i >= 0; i--) {
		for (int j : indbv[i])
			helper.update(j, 1);

		for (int j : indbv[i]) {
			bprime[j] = helper.query(j);
		}
	}

	helper = Fenwick(n + 3);
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j : indav[i])
			helper.update(j, 1);

		for (int j : indav[i]) {
			aprime[j] = helper.query(j);
			int og = indbv[i].back();
			// cout << j << " goes to " << og << endl;
			indbv[i].pop_back();
			// cout << "aka " << aprime[j] << " " << bprime[og] << endl;
			ans += abs(bprime[og] - aprime[j]);
		}
	}

	return ans;

}

int main() {

	int n; cin >> n;

	// coordinate compression
	vector<int> a(n), b(n);
	for (int &i : a) cin >> i;
	for (int &i : b) cin >> i;

	vector<int> v = a;
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	for (int &i : a) i = lower_bound(v.begin(), v.end(), i) - v.begin();
	for (int &i : b) i = lower_bound(v.begin(), v.end(), i) - v.begin();

	// code for numerical answer goes here
	cout << numerical(a, b) << "\n";

	construct(a, b);

}