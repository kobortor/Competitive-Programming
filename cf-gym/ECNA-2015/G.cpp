#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define int ll

const int MAXM = 27;

int m, n;
int bans[MAXM][6];
ll dp[MAXM][MAXM][1 << 6];

int32_t main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> m >> n;
    while (n--) {
        double x, y;
        cin >> x >> y;
        bans[int(x) + 1][int(y) + 1] = 1;
    }

    dp[0][3][0] = 1;
    int full = (1 << 4) - 1;
    for (int i = 1; i <= m; i++) {
        for (int msk = 0; msk <= full; msk++) dp[i][0][msk << 1] += dp[i - 1][3][msk];
        for (int j = 1; j <= 3; j++) {
            for (int msk = 0; msk <= full; msk++) {
                int rit = msk & (1 << (j - 1)), dwn = msk & (1 << j);
                if (!rit && !dwn) {
                    dp[i][j][msk] += dp[i][j - 1][msk];
                    if (!bans[i][j]) {
                        dp[i][j][msk ^ (1 << j)] += dp[i][j - 1][msk];
                        dp[i][j][msk ^ (1 << (j - 1))] += dp[i][j - 1][msk];
                    } 
                } else if (rit && !dwn && !bans[i][j]) dp[i][j][msk ^ (1 << (j - 1))] += dp[i][j - 1][msk];
                else if (!rit && dwn && !bans[i][j]) dp[i][j][msk ^ (1 << j)] += dp[i][j - 1][msk];
                //printf("%lld\n", dp[i][j - 1][msk]);
            }
        }
    }
    printf("%lld\n", dp[m][3][0]);
}
