#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;
// submit, accept
double dp[MAXN][MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<double> papers;
    for (int a = 0; a < n; a++) {
        double x;
        cin >> x;

        papers.push_back(x / 100.0);
    }

    sort(allof(papers));
    reverse(allof(papers));

    double ans = 0;

    dp[0][0] = 1;
    for (int a = 1; a <= n; a++) {
        dp[a][0] = dp[a - 1][0] * (1.0 - papers[a - 1]);
        for (int b = 1; b <= a; b++) {
            dp[a][b] = dp[a - 1][b - 1] * papers[a - 1]
                     + dp[a - 1][b] * (1.0 - papers[a - 1]);
        }

        double tmp = 0;
        for (int b = 1; b <= a; b++) {
            tmp += dp[a][b] * pow(b, (double)b / a);
        }

        ans = max(ans, tmp);
    }

    cout << fixed << setprecision(15) << ans;
}
