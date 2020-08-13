#include<bits/stdc++.h>

// Created by kobortor On 23:27:00 on 08-08-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MAXN = 1e5 + 5;

vector<pll> adj[MAXN];
ll cnt[MAXN];
ll sum = 0;
priority_queue<tuple<ll, ll, ll>> pq;

void dfs(int pos, int par) {
    cnt[pos] = 0;

    bool is_leaf = true;
    for (auto &[i, c] : adj[pos]) {
        if (i == par) continue;

        is_leaf = false;

        dfs(i, pos);
        cnt[pos] += cnt[i];

        sum += c * cnt[i];
        pq.push({(c - c / 2) * cnt[i], c / 2, cnt[i]});
    }

    if (is_leaf) {
        cnt[pos] = 1;
    }
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, S;
        cin >> n >> S;

        for (int i = 1, u, v, c; i <= n - 1; i++) {
            cin >> u >> v >> c;

            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        dfs(1, -1);

        int ans = 0;
        while (sum > S) {
            auto [reduce, cost, blw] = pq.top();
            pq.pop();

            sum -= reduce;

            ll new_reduce = (cost - cost / 2) * blw;
            pq.push({new_reduce, cost / 2, blw});

            ans++;
        }

        cout << ans << "\n";

        sum = 0;
        while (!pq.empty()) {
            pq.pop();
        }

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
    }
}
