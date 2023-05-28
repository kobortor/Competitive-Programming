#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define f first
#define s second

const int MN = 1e5 + 5;

int t, n;
pii a[MN];

//v_i + w_i >= lim + w_j if i carries j
//

bool check(int lim) {
    multiset<int> debuffs;
    multiset<int> power;
    for (int i = 1; i <= n; i++) {
        if (a[i].f < lim) {
            debuffs.insert(a[i].s);
        } else {
            power.insert(a[i].f + a[i].s);
        }
    }
    for (int p : debuffs) {
        auto it = power.lower_bound(lim + p);
        if (it == power.end()) return false;
        power.erase(it);
    }
    return true;
}

int32_t main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i].f >> a[i].s;
        int lo = 0, hi = 2e9, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) / 2;
            if (check(mid)) lo = mid;
            else hi = mid - 1;
        }
        printf("%lld\n", lo);
    }
}
