#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int dsu[MAXN];
int sz[MAXN];
ll out[MAXN];

int find (int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

ll c2(ll n) {
    return n * (n - 1) / 2;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int a = 1; a <= n; a++) {
        dsu[a] = a;
        sz[a] = 1;
    }

    vector<pair<int, pii>> edges;
    for (int a = 1; a <= n - 1; a++) {
        int u, v, c;
        cin >> u >> v >> c;

        edges.push_back({c, {u, v}});
    }

    vector<pii> queries;
    for (int a = 1; a <= m; a++) {
        int qi;
        cin >> qi;
        queries.push_back({qi, a});
    }

    sort(allof(edges));
    sort(allof(queries));

    int idx = 0;
    ll ans = 0;
    for (pii p : queries) {
        while (idx < (int)edges.size() && edges[idx].first <= p.first) {
            int fu = find(edges[idx].second.first);
            int fv = find(edges[idx].second.second);

            ans -= c2(sz[fu]);
            ans -= c2(sz[fv]);
            dsu[fu] = fv;
            sz[fv] += sz[fu];
            ans += c2(sz[fv]);

            idx++;
        }

        out[p.second] = ans;
    }

    for (int a = 1; a <= m; a++) {
        cout << out[a] << " ";
    }
}
