#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

int n;
int dp[MAXN][MAXN];
int adj[MAXN][MAXN];

int inc (int x) {
    return x == n ? 1 : x + 1;
}

int dec (int x) {
    return x == 1 ? n : x - 1;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            cin >> adj[a][b];
        }
    }

    for (int len = 1; len <= n - 1; len++) {
        for (int a = 1; a <= n; a++) {
            int b = a + len;
            if (b > n) {
                b -= n;
            }

            dp[a][b] = max(dp[inc(a)][b], dp[a][dec(b)]);
            if (adj[a][b]) {
                dp[a][b] = max(dp[a][b], dp[inc(a)][dec(b)] + 1);
            }

            for (int c = a; c != b; c = inc(c)) {
                dp[a][b] = max(dp[a][b], dp[a][c] + dp[inc(c)][b]);
            }
        }
    }

    int ans = dp[1][n];
    for (int a = 1; a + 1 <= n; a++) {
        ans = max(ans, dp[a + 1][a]);
    }

    cout << ans;
}
