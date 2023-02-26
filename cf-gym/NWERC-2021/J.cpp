#include <bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

const int MAXN = 5005;

typedef pair<int, int> pii;

double latitude[MAXN];
double longitude[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> latitude[i] >> longitude[i];
    }
    latitude[n + 1] = latitude[1];
    longitude[n + 1] = longitude[1];
    n++;

    // over the north or south poles
    for (int i = 1; i + 1 <= n; i++) {
        if (abs(longitude[i] - longitude[i + 1]) == 180) {
            cout << "yes\n";
            return 0;
        }
    }

    for (double x = -180; x < 180; x += 0.5) {
        bool good = false;
        for (int i = 1; i + 1 <= n; i++) {
            int lo = longitude[i];
            int hi = longitude[i + 1];
            if (lo > hi) {
                swap(lo, hi);
            }
            if (lo == hi) continue;
            if (hi - lo < 180) { // go lo -> hi
                good |= (lo <= x && x <= hi);
            } else { // go hi -> around -> lo
                good |= (hi <= x || x <= lo);
            }
        }
        if (!good) {
            cout << "no " << fixed << setprecision(1) << x << "\n";
            return 0;
        }
    }    
    cout << "yes\n";
}