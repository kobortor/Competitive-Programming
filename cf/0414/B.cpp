#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;
const ll mod = 1e9 + 7;

ll dp[MAXN][MAXN];

vector<int> factors[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    dp[0][1] = 1;

    int n, k;
    cin >> n >> k;

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= a; b++) {
            if (a % b == 0) {
                factors[a].push_back(b);
            }
        }
    }

    for (int a = 1; a <= k; a++) {
        for (int b = 1; b <= n; b++) {
            for (int f : factors[b]) {
                dp[a][b] += dp[a - 1][f];
            }
            dp[a][b] %= mod;
        }
    }

    ll ans = 0;
    for (int a = 1; a <= n; a++) {
        ans += dp[k][a];
    }
    cout << ans % mod;
}
