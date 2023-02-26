#include "bits/stdc++.h"

using namespace std;
#define ll long long
const int MAXN = 200200;

int n, m, q;
set<int> hq[MAXN];
int par[MAXN], sz[MAXN];
int ans1[MAXN], ans2[MAXN];

int gp(int x) {
	if (par[x] == x) return x;
	par[x] = gp(par[x]);
	return par[x];
}

void merge(int x, int y, int cc, vector<pair<int,int>> &tp) {
	x = gp(x);
	y = gp(y);
	if (x == y) return;
	
	if (sz[x] > sz[y]) swap(x, y);
	if (hq[x].size() > hq[y].size()) swap(hq[x], hq[y]);

	for (int z : hq[x]) {
		if (hq[y].count(z)) {

			hq[y].erase(z);
			tp.push_back({z, x});
			ans1[z] = cc;

		}
		else {
			hq[y].insert(z);
		}
	}

	hq[x].clear();

	sz[y] += sz[x];
	par[x] = y;

}

int main() {

	cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> q;

    vector<array<int,3>> edge;
    for (int i = 0; i < m; i++) {
    	int x, y, z; cin >> x >> y >> z;
    	edge.push_back({z, x, y});
    }

    sort(edge.begin(), edge.end());

    for (int i = 0; i < q; i++) {
    	int x, y; cin >> x >> y;
    	hq[x].insert(i);
    	hq[y].insert(i);
    }

    fill(sz, sz + MAXN, 1);
    iota(par, par + MAXN, 0);

    int ptt = -1;
    vector<pair<int,int>> todo;
    for (auto [cost, x, y] : edge) {
    	if (ptt != cost) {
    		for (auto [ind, node] : todo) {
    			ans2[ind] = sz[gp(node)];
    		}
    		todo.clear();
            ptt = cost;
    	}
    	merge(x, y, cost, todo);
    }

    for (auto [ind, node] : todo) {
    	ans2[ind] = sz[gp(node)];
    }

    fill(sz, sz + MAXN, 1);
    iota(par, par + MAXN, 0);

    for (int i = 0; i < q; i++) {
    	cout << ans1[i] << " " << ans2[i] << "\n";
    }

}