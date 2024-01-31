#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define int __int128

int sum2(int x) {
    if (x < 0) return 0;
    return x * (x + 1) * (2 * x + 1) / 6;
}

int sum2(int x, int y) { return sum2(y) - sum2(x - 1); }

int sum(int x) { return x * (x + 1) / 2; }

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        int n;
        ll N;
        cin >> N;
        n = N;
        int a = sqrtl(n);
        assert(a * a <= n && (a + 1) * (a + 1) > n);
        int ans = 0;
        int lo = 0, hi = a + 1, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (n <= mid * mid + mid - 1)
                hi = mid;
            else
                lo = mid + 1;
        }
        int y = lo;
        assert(y >= 1);
        int tmp = sum(y - 2) + n * (a - y + 1) - sum2(y, a);
        ans += tmp * 2;
        lo = 0, hi = 1e9;
        while (lo < hi) {
            mid = (lo + hi + 1) / 2;
            if (mid * mid + mid <= n)
                lo = mid;
            else
                hi = mid - 1;
        }
        ans += lo;
        printf("%lld\n", (ll)ans);
    }
}