#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int n, m, x, y;
int c[MAXN][2];

// [pos][col]
int dp[MAXN][2];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> x >> y;
    for (int a = 1; a <= n; a++) {
        string s;
        cin >> s;
        for (int b = 0; b < m; b++) {
            c[b + 1][s[b] == '#']++;
        }
    }

    memset(dp, 0x3f, sizeof dp);

    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int a = 1; a <= m; a++) {
        c[a][0] += c[a - 1][0];
        c[a][1] += c[a - 1][1];

        for (int b = max(0, a - y); b <= a - x; b++) {
            dp[a][0] = min(dp[a][0], dp[b][1] + (a - b) * n - (c[a][1] - c[b][1]));
            dp[a][1] = min(dp[a][1], dp[b][0] + (a - b) * n - (c[a][0] - c[b][0]));
        }
    }

    cout << min(dp[m][0], dp[m][1]);
}
