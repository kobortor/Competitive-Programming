#include<bits/stdc++.h>

// Created by kobortor On 23:27:00 on 08-08-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MAXN = 1e5 + 5;

vector<tuple<ll, ll, ll>> adj[MAXN];
ll sum = 0;
vector<ll> reduce1, reduce2;

ll dfs(int pos, int par) {
    ll ret_val = 0;

    bool is_leaf = true;
    for (auto &[i, w, c] : adj[pos]) {
        if (i == par) continue;

        is_leaf = false;

        ll cnt = dfs(i, pos);
        ret_val += cnt;

        sum += w * cnt;

        vector<ll> &reduce = (c == 1 ? reduce1 : reduce2);
        while (w) {
            reduce.push_back((w - w / 2) * cnt);
            w /= 2;
        }
    }

    if (is_leaf) {
        ret_val = 1;
    }
    return ret_val;
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, S;
        cin >> n >> S;

        for (int i = 1, u, v, w, c; i <= n - 1; i++) {
            cin >> u >> v >> w >> c;

            adj[u].push_back({v, w, c});
            adj[v].push_back({u, w, c});
        }

        dfs(1, -1);

        ll to_reduce = sum - S;
        if (to_reduce > 0) {
            sort(allof(reduce1));
            sort(allof(reduce2));
            reverse(allof(reduce1));

            ll cur_cost = reduce1.size();

            ll reduced = std::accumulate(allof(reduce1), 0ll);
            while (reduced < to_reduce) {
                reduced += reduce2.back();
                reduce2.pop_back();
                cur_cost += 2;
            }

            ll best = cur_cost;

            while (!reduce1.empty()) {
                cur_cost--;
                reduced -= reduce1.back();
                reduce1.pop_back();

                while (reduced < to_reduce && !reduce2.empty()) {
                    reduced += reduce2.back();
                    reduce2.pop_back();
                    cur_cost += 2;
                }

                if (reduced < to_reduce) {
                    break;
                }

                best = min(best, cur_cost);
            }

            cout << best << "\n";
        } else {
            cout << "0\n";
        }

        sum = 0;
        reduce1.clear();
        reduce2.clear();

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
    }
}
