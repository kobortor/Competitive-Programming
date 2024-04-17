#include <bits/stdc++.h>

using namespace std;
typedef pair<int ,int> pii;

const int MAXN = 26005;

double x, p;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> x >> p;        
    x /= 100;
    p /= 100;
    double q = 1 - p;

    double ans = 0;

    ans = max(ans, p - q * (1-x));

    array<double, MAXN> win_cur;
    win_cur[0] = 0;
    win_cur[1] = p;
    win_cur[2] = 1;

    pii best;
    for (int n = 3; n < MAXN; n++) {
        // win_cur.resize(n+1);

        // win_cur[n-1] = p + q * win_prv[n-2] * win_cur[n-1];
        win_cur[n-1] = p / (1 - q * win_cur[n-2]);
        double p_end = win_cur[n-1];

        for (int k = n - 2; k >= 1; k--) {
            win_cur[k] = win_cur[k] * p_end;
        }

        bool any_win = false;
        double prv = -1e9;
        for (int u = min(n-1, 2500); u >= 1; u--) {
            int l = u - n;
            double p_win = win_cur[-l];
            double p_lose = 1 - p_win;
            double value = p_win * u + p_lose * l * (1-x);

            if (value > ans) {
                ans = value;
                best = {u, l};
                any_win = true;
            }

            if (value > prv) {
                // ok
                prv = value;
            } else {
                break;
            }
        }
        if (!any_win) break;
    }
    // cout << best.first << " " << best.second << endl;
    cout << fixed << setprecision(10) << ans << endl;
}
