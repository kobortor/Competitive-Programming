#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pt;

const int MAXN = 1005;

int n;
vector<int> adj[MAXN];
int sz[MAXN];
pt ans[MAXN];

const double pi = acos(-1);

void dfs1(int pos, int par) {
    sz[pos] = 0;
    for (int i : adj[pos]) {
        if (i != par) {
            dfs1(i, pos);
            sz[pos] += sz[i];
        }
    }

    // count leaves
    if (sz[pos] == 0) {
        sz[pos] = 1;
    }
}

void dfs2(int pos, int par, pt p, double lo, double hi) {
    ans[pos] = p;

    int children = sz[pos];
    int seen = 0;
    double range = hi - lo;
    for (int i : adj[pos]) {
        if (i == par) continue;

        double new_lo = lo + range * seen / children;
        double new_hi = lo + range * (seen + sz[i]) / children;

        double mid = (new_lo + new_hi) / 2;

        double dx = cos(mid);
        double dy = sin(mid);

        dfs2(i, pos, {p.first + dx, p.second + dy}, new_lo, new_hi);

        seen += sz[i];
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, -1);
    dfs2(1, -1, pt(0, 0), -pi / 2, pi / 2);

    for (int i = 1; i <= n; i++) {
        cout << fixed << setprecision(8) << ans[i].first << " " << ans[i].second << '\n';
    }
}
