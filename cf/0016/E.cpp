#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 18;

double A[MAXN][MAXN];
double dp[1 << MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    dp[(1 << n) - 1] = 1;
    for (int state = (1 << n) - 1; state > 0; state--) {
        int valid = __builtin_popcount(state);
        int pairs = valid * (valid - 1) / 2;
        double prod = 1.0 / pairs;

        for (int i = 0; i < n; i++) {
            if (!(state & (1 << i))) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                if (!(state & (1 << j))) {
                    continue;
                }

                // `i` gets rekt
                dp[state & ~(1 << i)] += dp[state] * A[j][i] * prod;

                // `j` gets rekt
                dp[state & ~(1 << j)] += dp[state] * A[i][j] * prod;
            }
        }
    }

    cout << fixed << setprecision(15);
    for (int i = 0; i < n; i++) {
        cout << dp[1 << i] << " ";
    }
}
