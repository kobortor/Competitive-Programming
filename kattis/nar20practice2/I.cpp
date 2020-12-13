#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int dp[MAXN][MAXN][2];
int grid[MAXN][MAXN];
int prefix[MAXN][MAXN];

int p, q;
// p = #rows
// q = #columns

int range(int x1, int x2, int y1, int y2) {
    return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
}

int solve(int x, int y, int person) {
    if (dp[x][y][person] != 0x3f3f3f3f) {
        return dp[x][y][person];
    }

    if (x > q || y < 1) {
        return 0;
    }

    int ans = -1e9;
    if (person == 0) {
        // eat from west side
        // increase 
        for (int k = x; k <= q; k++) {
            int eaten = range(x, k, 1, y);
            // cout << x << " " << y << " " << person << " " << k << " gets " << eaten << endl;

            ans = max(ans, eaten - solve(k + 1, y, !person));
        }
    } else {
        for (int k = y; k >= 1; k--) {
            int eaten = range(x, q, k, y);
            // cout << x << " " << y << " " << person << " " << k << " gets " << eaten << endl;

            ans = max(ans, eaten - solve(x, k - 1, !person));
        }
    }

    // cout << x << " " << y << " " << person << " = " << ans << endl;
    return dp[x][y][person] = ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dp[i][j][0] = 0x3f3f3f3f;
            dp[i][j][1] = 0x3f3f3f3f;
        }
    }

    cin >> p >> q;
    
    for (int i = 1; i <= 100; i++) {
        int sum = 0;
        for (int j = 1; j <= 100; j++) {
            grid[i][j] = (i % 2) == (j % 2) ? +1 : -1;

            sum += grid[i][j];
            prefix[i][j] = prefix[i - 1][j] + sum;
            // cout << grid[i][j] << " ";
        }
        // cout << endl;
    }

    cout << solve(1, p, 0) << endl;
}
