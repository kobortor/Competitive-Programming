#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MN = 1005;

int n, a[MN], dp[MN][MN][2], vis[MN][MN][2]; //stores a - b; (p1 maximize, p2 minimize)

int rec(int l, int r, int t) {
    if (vis[l][r][t]) return dp[l][r][t];
    vis[l][r][t] = 1;
    if (t) {
        if (l == r) dp[l][r][t] = -a[l];
        else {
            if (a[r] > a[l]) dp[l][r][t] = rec(l, r - 1, 0) - a[r];
            else dp[l][r][t] = rec(l + 1, r, 0) - a[l];
        }
        return dp[l][r][t];
    } else {
        if (l == r) dp[l][r][t] = a[l];
        else {
            dp[l][r][t] = max(rec(l, r - 1, 1) + a[r], rec(l + 1, r, 1) + a[l]);
        }
        return dp[l][r][t];
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int g = 0;
    while (++g) {
        cin >> n;
        if (!n) break;
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(vis, 0, sizeof(vis));
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", g, rec(1, n, 0));
    }
}