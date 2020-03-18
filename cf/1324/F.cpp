#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];

int dp[MAXN];

void dfs1(int pos, int par) {
    for (int i : adj[pos]) {
        if (i != par) {
            dfs1(i, pos);
            dp[pos] += max(0, dp[i]);
        }
    }
}

void dfs2(int pos, int par, int abv) {
    for (int i : adj[pos]) {
        if (i != par) {
            dfs2(i, pos, max(0, abv + dp[pos] - max(0, dp[i])));
        }
    }
    dp[pos] += abv;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 1, col; i <= n; i++) {
        cin >> col;
        dp[i] = col == 1 ? 1 : -1;
    }

    for (int i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1, 0);

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
}
