#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 6;
const int MAXL = 22;

int n;
ll heat[MAXN];
ll prefix[MAXN];
ll sparse[MAXN][MAXL];

ll k_lookup[MAXN];

// inclusive
ll max_query(int l, int r) {
    int k = k_lookup[r - l + 1];
    ll ans = max(sparse[l][k], sparse[r - (1 << k) + 1][k]);
    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 1, k = 0; i < MAXN; i++) {
        if ((1 << (k + 1)) < i) {
            k++;
        }
        k_lookup[i] = k;
    }

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> heat[i];
        heat[i + n] = heat[i];
        heat[i + 2 * n] = heat[i];
    }
    for (int i = 1; i <= 3 * n; i++) {
        prefix[i] = prefix[i - 1] + heat[i];
    }
    for (int i = 1; i <= 3 * n; i++) {
        sparse[i][0] = heat[i];
    }
    for (int k = 1; k < MAXL; k++) {
        int jmp = 1 << (k - 1);
        for (int i = 1; i <= 3 * n; i++) {
            if (i + jmp <= 3 * n) {
                sparse[i][k] = max(sparse[i][k - 1], sparse[i + jmp][k - 1]);
            } else {
                sparse[i][k] = sparse[i][k - 1];
            }
        }
    }

    ll ans = 1e15;
    for (int i = 1; i <= n; i++) {
        // cout << endl;
        // cout << "Testing " << i << endl;
        ll buff = heat[i];
        ll tot = 0;

        int lo, hi;
        
        int l = i + n;
        int r = i + n;
        while (r - l + 1 < n) {
            // cout << "Round " << l << " " << r << "\n";;
            int old_l, old_r;
            while (true) {
                tot = prefix[r] - prefix[l - 1] + buff;
                // cout << "tot = " << tot << " from " << l << " to " << r << " and " << buff << endl;
                old_l = l;
                old_r = r;
                // cout << " -- left --\n";

                // try expanding left
                lo = 1;
                hi = l - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (max_query(mid, l - 1) <= tot) {
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                l = lo;
                // cout << " -- right --\n";

                // try expanding right
                lo = r + 1;
                hi = 3 * n;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (max_query(r + 1, mid) <= tot) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                r = hi;

                if (l == old_l && r == old_r) {
                    break;
                }
            }
            if (r - l + 1 >= n) {
                // cout << i << " ends at " << l - n << " " << r - n << endl;
                break;
            }

            // pick which side to buff (buff the cheaper one)
            ll new_buff = min(heat[l - 1], heat[r + 1]) - tot;
            buff += new_buff;
            tot += new_buff;
        }

        // cout << i << " buff " << buff << endl;
        ans = min(ans, buff);
    }
    cout << ans << "\n";
}