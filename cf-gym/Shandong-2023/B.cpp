#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 300300;


set<pair<int,int>> curr;
int still[MAXN];
vector<pair<ll,ll>> req[MAXN];
vector<pair<ll,ll>> need[MAXN], give[MAXN];
ll ch[MAXN];

void add(ll ty, ll val) {
    
    ch[ty] += val;

    while (req[ty].size()) {
        ll cn = req[ty].back().first;
        if (ch[ty] >= cn) {
            int ci = req[ty].back().second;
            req[ty].pop_back();
            curr.erase({still[ci], ci});
            still[ci]--;
            curr.insert({still[ci], ci});
        }
        else break;
    }

}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int g; cin >> g;

    vector<ll> v;

    vector<pair<ll,ll>> groups(g);
    for (auto &[x, y] : groups) {
        cin >> x >> y;
        v.push_back(x);
    }

    int m; cin >> m;

    for (int i = 0; i < m; i++) {
        int cn, cg; cin >> cn;
        still[i] = cn;
        curr.insert({still[i], i});
        while (cn--) {
            ll u, vf; cin >> u >> vf;
            need[i].push_back({u, vf});
            v.push_back(u);
        }
        cin >> cg;
        while (cg--) {
            ll u, vf; cin >> u >> vf;
            give[i].push_back({u, vf});
            v.push_back(u);
        }
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    auto get = [&](ll x) {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    };

    for (auto &[x, y] : groups) {
        x = get(x);
    }
    for (int ci = 0; ci < m; ci++) {
        for (auto &[x, y] : need[ci]) {
            x = get(x);
            req[x].push_back({y, ci});
        }
    }
    for (int ci = 0; ci < m; ci++) {
        for (auto &[x, y] : give[ci]) {
            x = get(x);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        sort(req[i].begin(), req[i].end());
        reverse(req[i].begin(), req[i].end());
    }

    for (auto [x, y] : groups) {
        add(x, y);
    }

    int ans = 0;
    while (curr.size() && (curr.begin()->first == 0)) {
        int tt = curr.begin()->second;
        curr.erase(curr.begin());
    
        ans++;


        for (auto [x, y] : give[tt]) {
            add(x, y);
        }

    }

    cout << ans << "\n";

}
