#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
int n;

ll out[MAXN];

ll vi[MAXN], di[MAXN];

ll price[MAXN];

struct tag {
    ll mx, mn, diff;
    tag () {}
    tag (tag t1, tag t2) {
        mx = max(t1.mx, t2.mx);
        mn = min(t1.mn, t2.mn);

        diff = max(max(t1.diff, t2.diff), t2.mx - t1.mn);
    }
};

struct node {
    int l, r;
    tag t;
} tr[MAXN * 4];

void build (int l, int r, int pos) {
    tr[pos].l = l;
    tr[pos].r = r;

    if (l == r) {
        tr[pos].t.mx = price[l];
        tr[pos].t.mn = price[l];
        tr[pos].t.diff = 0;
    } else {
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
        
        tr[pos].t = tag(tr[pos << 1].t, tr[pos << 1 | 1].t);
    }
}

tag query (int l, int r, int pos) {
    if (tr[pos].l == l && tr[pos].r == r) {
        return tr[pos].t;
    }

    int mid = tr[pos << 1].r;
    if (r <= mid) {
        return query (l, r, pos << 1);
    } else if (l > mid) {
        return query (l, r, pos << 1 | 1);
    } else {
        return tag( query(l, mid, pos << 1),
                    query(mid + 1, r, pos << 1 | 1));
    }
}

void solve (vector<pair<int, pii>> queries) {
    vector<pair<int, pii>> mods[7];
    for (auto au : queries) {
        mods[au.second.first % 7].push_back(au);
    }

    for (int modv = 0; modv < 7; modv++) {
        for (int a = 0; a < n; a++) {
            int offset = (a - modv + 7) % 7;
            price[a] = vi[a] + min(offset, 6 - offset) * di[a];
        }

        build (0, n - 1, 1);

        for (auto au : mods[modv]) {
            out[au.first] = query(au.second.first, au.second.second, 1).diff;
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;

    for (int a = 0; a < n; a++) {
        cin >> vi[a] >> di[a];
    }

    vector<pair<int, pii>> inc, dec;

    int q;
    cin >> q;
    for (int a = 0; a < q; a++) {
        int s, t;
        cin >> s >> t;

        if (s == t) {
            out[a] = 0;
        } else if (s < t) {
            inc.push_back({a, {s - 1, t - 1}});
        } else {
            dec.push_back({a, {n - s, n - t}});
        }
    }

    solve(inc);

    reverse(vi, vi + n);
    reverse(di, di + n);

    solve(dec);

    for (int a = 0; a < q; a++) {
        cout << out[a] << "\n";
    }
}
