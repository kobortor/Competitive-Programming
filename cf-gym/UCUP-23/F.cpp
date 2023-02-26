#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAX = 1000010;

int ci;
int lc[MAX], rc[MAX];
vector<pair<int,int>> g[MAX];

void construct(int curr, int cmin, int cmax) {

	if (cmin == cmax) {
		return;
	}

	int mid = (cmin + cmax) / 2;

	lc[curr] = ci;
	g[curr].push_back({ci, 0});
	g[ci].push_back({curr, 0});
	construct(ci++, cmin, mid);

	rc[curr] = ci;
	g[curr].push_back({ci, 0});
	g[ci].push_back({curr, 0});
	construct(ci++, mid + 1, cmax);

}

void get_segs(int c, int cmin, int cmax, int minb, int maxb, vector<pair<int,int>> &tp) {

	if (cmin >= minb && cmax <= maxb) {
		tp.push_back(c);
		return;
	}
	if (cmin > maxb || cmax < minb) return;

	int mid = (cmin + cmax) / 2;
	get_segs(lc[c], cmin, mid, minb, maxb, tp);
	get_segs(rc[c], mid + 1, cmax, minb, maxb, tp);

}

void reset_it() {

	for (int i = 0; i < ci; i++) {
		g[i].clear();
	}

}

void solve() {

	int n; cin >> n;

	ci = n + 1;

	int rt1 = ci;
	construct(rt1, 1, n);	

	int rt2 = ci;
	construct(rt2, 1, n);

	int q; cin >> q;

	vector<pair<int,int>> vals;
	for (int i = 0; i < q; i++) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		vals.push_back({ci, ci + 1});

		{
			vector<pair<int,int>> 
		}

	}


}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {

    	solve();

    }

}
