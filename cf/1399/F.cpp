#include<bits/stdc++.h>

// Created by kobortor On 14:02:24 on 10-08-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3005;

vector<pii> lines;

int cache[MAXN];

int solve(int idx) {
    if (cache[idx] != -1) return cache[idx];

    vector<tuple<int, int, int>> contain;
    for (int i = 0; i < (int)lines.size(); i++) {
        if (i == idx) continue;

        if (lines[idx].first <= lines[i].first && lines[i].second <= lines[idx].second) {
            contain.push_back({lines[i].first, lines[i].second, solve(i)});
        }
    }

    sort(allof(contain));

    int best_prv = 1;
    int best_val = 1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto [l, r, v] : contain) {
        while (!pq.empty() && pq.top().first < l) {
            best_prv = max(best_prv, pq.top().second);
            pq.pop();
        }

        pq.push({r, best_prv + v});
        best_val = max(best_val, best_prv + v);
    }

    return cache[idx] = best_val;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        memset(cache, -1, (n + 1) * sizeof cache[0]);

        lines.push_back({-1e9, 1e9});

        for (int i = 0, l, r; i < n; i++) {
            cin >> l >> r;
            lines.push_back({l, r});
        }

        cout << solve(0) - 1 << "\n";

        lines.clear();
    }
}
