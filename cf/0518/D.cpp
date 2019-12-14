#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, t;
    double p;
    cin >> n >> p >> t;

    vector<double> dp(n + 2);
    dp[n] = 1;

    while (t--) {
        dp[0] += dp[1] * p;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i + 1] * p + dp[i] * (1 - p);
        }
    }

    double ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[i] * (n - i);
    }

    cout << fixed << setprecision(15) << ans;
}
