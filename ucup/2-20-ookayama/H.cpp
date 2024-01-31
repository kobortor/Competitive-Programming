#include "bits/stdc++.h"

using namespace std;

#define ll long long

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SuffixArray {
    vi sa, lcp;

    SuffixArray(string &s, int lim = 256) {
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s) + 1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i, 0, n) ws[x[i]]++;
            rep(i, 1, lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i, 1, n) a = sa[i - 1], b = sa[i],
                         x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1
                                                                       : p++;
        }
        rep(i, 1, n) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k &&k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++)
                ;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> sids;
    string S;
    vector<int> dollars;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sids.push_back(vector<int>());
        for (char c : s) {
            sids.back().push_back(S.size());
            S.push_back(c);
        }
        dollars.push_back(S.size());
        S.push_back('$');
    }

    SuffixArray foo(S);

    ll ans = 0;
    vector<int> posn(S.size() + 1);
    for (int i = 0; i < foo.sa.size(); i++) {
        posn[foo.sa[i]] = i;
    }

    for (auto &v : sids) {
        for (int &i : v) {
            i = posn[i];
        }

        sort(v.begin(), v.end());

        int pb = 1e9;
        int pv = 0;

        while (v.size()) {
            int x = v.back();
            v.pop_back();

            if (x == pb - 1) {
                pv = min(pv, foo.lcp[x + 1]);
            } else {
                pv = (x + 1 == foo.lcp.size() ? 0 : foo.lcp[x + 1]);
            }
            pb = x;

            int wx = foo.sa[x];
            int ni = *lower_bound(dollars.begin(), dollars.end(), wx);

            int upper = ni - wx;

            int lower = foo.lcp[x];
            lower = max(lower, pv);

            if (upper >= lower) {
                ans += (upper - lower);
            }
        }
    }

    cout << ans << "\n";
}