#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

set<pll> best[MAXN];
bool repair[MAXN];

vector<pll> adj[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m, t, d;
    cin >> n >> m >> t >> d;

    repair[1] = true;
    while (t--) {
        ll x;
        cin >> x;
        repair[x] = true;
    }

    while (m--) {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    // time, repair
    queue<pair<ll, pll>> q;
    q.push({1, {0, d}});

    best[1].insert({0, d});

    while (!q.empty()) {
        pair<ll, pll> fr = q.front();
        q.pop();

        ll pos = fr.first;
        ll tm = fr.second.first, rep = fr.second.second;

        if (best[pos].find(fr.second) == best[pos].end()) continue;

        for (pll p : adj[pos]) {
            if (p.second > rep) continue;

            pll nxt = { tm + p.second, rep - p.second };
            if (repair[p.first]) {
                nxt.second = d;
            }

            auto au = best[p.first].insert(nxt);
            if (!au.second) continue;

            auto iter = au.first;

            // something faster has at least as much duration
            if (iter != best[p.first].begin() && prev(iter)->second >= iter->second) {
                best[p.first].erase(iter);
                continue;
            }

            // something has same time but more duration
            if (next(iter) != best[p.first].end() && next(iter)->first == iter->first) {
                best[p.first].erase(iter);
                continue;
            }

            // get rid of those who have the same time but less duration
            while (iter != best[p.first].begin() && prev(iter)->first == iter->first) {
                best[p.first].erase(prev(iter));
            }

            // get rid of those with more time and less duration
            while (next(iter) != best[p.first].end() && next(iter)->second <= iter->second) {
                best[p.first].erase(next(iter));
            }

            q.push({p.first, *iter});
        }
    }

    if (best[n].empty()) {
        cout << "stuck";
    } else {
        cout << best[n].begin()->first;
    }
}
