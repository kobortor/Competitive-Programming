#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305;

#define allof(x) (x).begin(), (x).end()

int n;

struct alien {
    int A, B, D;
} aliens[MAXN];

// dp[l][r]
int dp[2 * MAXN][2 * MAXN];

int solve(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    if (r < l) {
        return dp[l][r] = 0;
    }

    int h = -1;
    for (int i = 0; i < n; i++) {
        if (l <= aliens[i].A && aliens[i].B <= r) {
            h = max(h, aliens[i].D);
        }
    }

    if (h == -1) {
        return dp[l][r] = 0;
    }

    int ans = 0x3f3f3f3f;
    for (int i = l; i <= r; i++) {
        ans = min(ans, h + solve(l, i - 1) + solve(i + 1, r));
    }
    return dp[l][r] = ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        memset(dp, -1, sizeof dp);

        vector<int> times;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> aliens[i].A;
            cin >> aliens[i].B;
            cin >> aliens[i].D;

            times.push_back(aliens[i].A);
            times.push_back(aliens[i].B);
        }

        sort(allof(times));
        times.erase(unique(allof(times)), times.end());

        for (int i = 0; i < n; i++) {
            aliens[i].A = lower_bound(allof(times), aliens[i].A) - times.begin();
            aliens[i].B = lower_bound(allof(times), aliens[i].B) - times.begin();
        }

        cout << solve(0, times.size() - 1) << endl;
    }
}

