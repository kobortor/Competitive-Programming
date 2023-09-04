#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct edge {
    int u, v, w;
};

const int MN = 22;

int n, m, u, v, c, par[MN];
edge a[MN];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[x] = y;
    return true;
}

void reset() {
    for (int i = 1; i <= n; i++) par[i] = i;
}

bool connected() {
    for (int i = 1; i < n; i++) {
        if (find(i) != find(i + 1)) return false;
    }
    return true;
}

bool ok(const vector<edge>& v) {
    for (int i = 0; i < v.size(); i++) {
        reset();
        for (int j = 0; j < v.size(); j++) {
            if (i == j) continue;
            merge(v[j].u, v[j].v);
        }
        if (!connected()) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int g = 0;
    while (++g) {
        cin >> n >> m;
        if (!n && !m) break;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> c;
            a[i] = {u, v, c};
        }
        int ans = 0x3f3f3f3f;
        for (int msk = 1; msk < 1 << m; msk++) {
            vector<edge> v;
            int cost = 0;
            for (int i = 0; i < m; i++) {
                if (msk & (1 << i)) v.push_back(a[i]), cost += a[i].w;
            }
            if (ok(v)) {
                ans = min(ans, cost);
            }
        }
        if (ans == 0x3f3f3f3f) printf("There is no reliable net possible for test case %d.\n", g);
        else printf("The minimal cost for test case %d is %d.\n", g, ans);
    }
}