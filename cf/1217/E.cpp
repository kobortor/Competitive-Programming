#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const int BITS = 10;

struct node {
    int l, r;
    array<pii, BITS> vals;
} tr[MAXN * 4];

pii merge (pii p1, pii p2) {
    if (p1.first < p2.first) {
        return pii(p1.first, min(p1.second, p2.first));
    } else {
        return pii(p2.first, min(p2.second, p1.first));
    }
}

array<pii, BITS> merge (array<pii, BITS> a1, array<pii, BITS> a2) {
    array<pii, BITS> arr;
    for (int a = 0; a < BITS; a++) {
        arr[a] = merge (a1[a], a2[a]);
    }
    return arr;
}

void pushup (int pos) {
    tr[pos].vals = merge (tr[pos << 1].vals, tr[pos << 1 | 1].vals);
}

array<pii, BITS> gen_array (int x) {
    array<pii, BITS> ans;
    int orig_x = x;
    for (int a = 0; a < BITS; a++) {
        if (x % 10 != 0) {
            ans[a] = pii(orig_x, INT_MAX);
        } else {
            ans[a] = pii(INT_MAX, INT_MAX);
        }
        x /= 10;
    }
    return ans;
}

void build (int l, int r, int pos) {
    tr[pos].l = l;
    tr[pos].r = r;

    if (l == r) {
        int x;
        cin >> x;
        tr[pos].vals = gen_array(x);
    } else {
        int mid = (l + r) / 2;
        build (l, mid, pos << 1);
        build (mid + 1, r, pos << 1 | 1);
        pushup (pos);
    }
}

void update (int loc, int pos, int x) {
    if (tr[pos].l == tr[pos].r) {
        tr[pos].vals = gen_array(x);
    } else {
        int mid = tr[pos << 1].r;
        if (loc <= mid) {
            update (loc, pos << 1, x);
        } else {
            update (loc, pos << 1 | 1, x);
        }
        pushup (pos);
    }
}

array<pii, BITS> query (int l, int r, int pos) {
    if (tr[pos].l == l && tr[pos].r == r) {
        return tr[pos].vals;
    } else {
        int mid = tr[pos << 1].r;
        if (r <= mid) return query (l, r, pos << 1);
        else if (l > mid) return query (l, r, pos << 1 | 1);
        else return merge (query (l, mid, pos << 1), query (mid + 1, r, pos << 1 | 1));
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    build (1, N, 1);

    while (M--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int i, x;
            cin >> i >> x;
            update (i, 1, x);
        } else {
            int l, r;
            cin >> l >> r;

            array<pii, BITS> res = query (l, r, 1);
            int ans = INT_MAX;
            for (pii p : res) {
                if (p.second != INT_MAX) {
                    ans = min(ans, p.first + p.second);
                }
            }
            if (ans == INT_MAX) {
                cout << "-1\n";
            } else {
                cout << ans << "\n";
            }
        }
    }
}
