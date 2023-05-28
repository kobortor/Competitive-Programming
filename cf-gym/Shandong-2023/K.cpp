include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Range {
    int l, r, n;
    char lft, rht;

    int get_lo() {
        if (n == 0) return 0;

        if (lft == 'x') {
            if (rht == 'x') {
                return 0;
            } else {
                return 0;
            }
        }
        if (rht == 'x') {
            return 0;
        }
        if (lft == rht) {
            return 0;
        } else {
            return 1;
        }
    }

    int get_hi() {
        if (n == 0) return 0;

        if (lft == 'x') {
            if (rht == 'x') {
                return n - 1;
            } else {
                return n;
            }
        }
        if (rht == 'x') {
            return n;
        }
        if (lft == rht) {
            if (n % 2 == 0) return n;
            else return n + 1;
        } else {
            if (n % 2 == 0) return n + 1;
            else return n;
        }
    }
};

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        if (s.back() != '?') {
            char c;
            if (k % 2 == 0) {
                c = s.back();
            } else {
                c = '0' + ('1' - s.back());
            }
            if (s[0] == '?') {
                s[0] = c;
            }
        }

        s = "x" + s + "x";

        deque<Range> ranges;

        for (int i = 1; i <= n; i++) {
            if (s[i] == '?') {
                int j = i;
                while (s[j + 1] == '?') {
                    j++;
                }
                ranges.push_back({i, j, j - i + 1, s[i - 1], s[j + 1]});
                i = j;
            }
        }

        int lo = 0, hi = 0;
        for (int i = 1; i + 1 <= n; i++) {
            char u = s[i], v = s[i + 1];
            if (u != '?' && v != '?' && u != v) {
                lo++;
                hi++;
            }
        }

        for (Range r : ranges) {
            lo += r.get_lo();
            hi += r.get_hi();
        }

        while (!ranges.empty()) {
            Range &r = ranges[0];

            Range r0 = {r.l + 1, r.r, r.n - 1, '0', r.rht};
            Range r1 = {r.l + 1, r.r, r.n - 1, '1', r.rht};

            // try zero
            int new_diff_0 = 0;
            new_diff_0 += (r.lft == '1'); // left new diff
            new_diff_0 += (r.n == 1 && r.rht == '1'); // right new diff

            int new_lo_0 = lo - r.get_lo() + r0.get_lo() + new_diff_0;
            int new_hi_0 = hi - r.get_hi() + r0.get_hi() + new_diff_0;

            int new_diff_1 = 0;
            new_diff_1 += (r.lft == '0'); // left new diff
            new_diff_1 += (r.n == 1 && r.rht == '0'); // right new diff

            int new_lo_1 = lo - r.get_lo() + r1.get_lo() + new_diff_1;
            int new_hi_1 = hi - r.get_hi() + r1.get_hi() + new_diff_1;

            if (new_lo_0 <= k && k <= new_hi_0) {
                s[r.l] = '0';
                lo = new_lo_0;
                hi = new_hi_0;
                ranges[0] = r0;
            } else {
                s[r.l] = '1';
                lo = new_lo_1;
                hi = new_hi_1;
                ranges[0] = r1;
            }

            if (ranges[0].n == 0) {
                ranges.pop_front();
            }
        }
        s = s.substr(1, s.size() - 2);

        if (lo <= k && k <= hi) {
            cout << s << endl;
        } else {
            cout << "Impossible\n";
        }
    }
}
