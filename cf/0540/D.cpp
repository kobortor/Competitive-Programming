#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 101;

double dp[MAXN][MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int r, s, p;
    cin >> r >> s >> p;

    dp[r][s][p] = 1;
    for (int rr = r; rr >= 0; rr--) {
        for (int ss = s; ss >= 0; ss--) {
            for (int pp = p; pp >= 0; pp--) {
                double prob = dp[rr][ss][pp];
                double denom = rr * ss + ss * pp + rr * pp;

                // paper beats rock
                if (rr != 0 && pp != 0) {
                    dp[rr - 1][ss][pp] += rr * pp * prob / denom;
                }

                // rock beats scissor
                if (ss != 0 && rr != 0) {
                    dp[rr][ss - 1][pp] += ss * rr * prob / denom;
                }

                // scissor beats paper
                if (pp != 0 && ss != 0) {
                    dp[rr][ss][pp - 1] += pp * ss * prob / denom;
                }
            }
        }
    }

    double ans_r = 0;
    double ans_s = 0;
    double ans_p = 0;

    for (int i = 1; i <= r; i++) ans_r += dp[i][0][0];
    for (int i = 1; i <= s; i++) ans_s += dp[0][i][0];
    for (int i = 1; i <= p; i++) ans_p += dp[0][0][i];

    cout << fixed << setprecision(15) << ans_r << " " << ans_s << " " << ans_p;
}
