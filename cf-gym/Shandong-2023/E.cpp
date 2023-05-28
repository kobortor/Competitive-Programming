#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

__int128 n, k, m, a, b;
bool good(__int128 lo, __int128 hi) {
    bool ans = false;
    ans |= lo % m == 0;
    ans |= hi/m != lo/m;
    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll T;
    cin >> T;
    while (T--) {
        ll tmp;

        cin >> tmp; n = tmp;
        cin >> tmp; k = tmp;
        cin >> tmp; m = tmp;
        cin >> tmp; a = tmp;
        cin >> tmp; b = tmp;

        __int128 orig_n;

        ll ans = 1e18;

        if (k == 1) {
            cout << (n % m == 0 ? "0\n" : "-1\n");
        } else {
            int num_b_ops = 0;
            while (true) {
                int num_a_ops = 0;
                __int128 lo = n, hi = n;
                while (true) {
                    if (good(lo, hi)) {
                        ans = min(ans, ll(num_b_ops * b + num_a_ops * a));
                        break;
                    }

                    lo = lo * k;
                    hi = hi * k + (k - 1);
                    num_a_ops++;
                }

                if (n == 0) {
                    break;
                }
                n /= k;
                num_b_ops++;
            }

            cout << ans << endl;
        }
    }
}
