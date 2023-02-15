#include<bits/stdc++.h>

// Created by kobortor On 14:46:45 on 15-02-2023

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

const ll mod = 998244353;

int mindist[MAXN];
vector<int> adj[MAXN];

int dist(pii p1, pii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int n;
pii points[MAXN];
ll npk[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    npk[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        npk[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            npk[i][j] = (npk[i - 1][j - 1] * j + npk[i - 1][j]) % mod;
        }
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < n; i++) {
        mindist[i] = 1e9;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            int d = dist(points[i], points[j]);
            if (d < mindist[i]) {
                mindist[i] = d;
                adj[i] = {j};
            } else if (d == mindist[i]) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> sizes;
    for (int i = 0; i < n; i++) {
        set<int> vis = {i};
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            for (int j : adj[fr]) {
                if (!vis.count(j)) {
                    q.push(j);
                    vis.insert(j);
                }
            }
        }

        if (*vis.begin() == i && all_of(allof(vis), [&](int x) {
                return mindist[x] == mindist[i] && adj[x].size() == vis.size() - 1;
            })) {
            sizes.push_back(vis.size());
        }
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    dp[0][0] = 1;
    for (int s : sizes) {
        for (int i = n; i >= 1; i--) {
            for (int j = n; j >= s; j--) {
                dp[i][j] += dp[i - 1][j - s];
                dp[i][j] %= mod;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) { // Groups chosen
        for (int j = 0; j <= n; j++) {
            ans = (ans + npk[n][i + (n - j)] * dp[i][j]) % mod;
        }
    }
    cout << ans << endl;
}
