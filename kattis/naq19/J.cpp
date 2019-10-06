#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

double deck[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    for (int a = 1; a <= N; a++) {
        cin >> deck[a];
    }

    double lo = 0, hi = 2e9;

    for (int round = 0; round < 500; round++) {
        double mid = (lo + hi) / 2;

        bool good = false;

        double accum = 0;
        for (int a = 1; a <= N; a++) {
            accum += deck[a] - mid;
            if (accum > 0) {
                good = true;
                break;
            }
        }

        if (!good) {
            accum = 0;
            for (int a = N; a >= 1; a--) {
                accum += deck[a] - mid;
                if (accum > 0) {
                    good = true;
                    break;
                }
            }
        }

        if (good) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << fixed << setprecision(15) << lo;
}
