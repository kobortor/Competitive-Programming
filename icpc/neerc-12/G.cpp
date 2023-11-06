#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MN = 60, MK = 1005;



int n, k, dp[MN][MK][2]; // index, cur digit, under yet

int32_t main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("great.in", "r", stdin);
    freopen("great.out", "w", stdout);

    cin >> n >> k;
    vector<int> digs;
    while (n) {
        digs.push_back(n % k);
        n /= k;
    }
    int len = digs.size();
    if (len % 2 == 1) {
        for (int i = 0; i <= digs[len - 1]; i++) {
            if (i < digs[len - 1]) dp[len - 1][i][1] = 1;
            else dp[len - 1][i][0] = 1;
        }
    } else {
        dp[len - 1][0][1] = 1;
    }
    for (int i = len - 2; i >= 0; i--) {
        for (int curdig = 0; curdig < k; curdig++) {
            if (i % 2 == 1 && curdig > 0) break;
            for (int predig = 0; predig < k; predig++) {
                if (i % 2 == 0 && predig > 0) break;
                for (int under = 0; under < 2; under++) {
                    if (!under && curdig > digs[i]) continue;
                    int newunder = under | (curdig < digs[i]);
                    dp[i][curdig][newunder] += dp[i + 1][predig][under];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) ans += dp[0][i][0] + dp[0][i][1];
    printf("%lld\n", ans);

}
