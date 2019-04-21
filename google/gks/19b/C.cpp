#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

struct node {
    int l, r, mx, lz;
} tr[4 * MAXN];

void build (int l, int r, int pos) { 
    tr[pos].l = l;
    tr[pos].r = r;
    tr[pos].mx = 0;
    tr[pos].lz = 0;

    if (l != r) {
        int mid = (l + r) / 2;
        build (l, mid, pos << 1);
        build (mid + 1, r, pos << 1 | 1);
    }
}

void update (int l, int r, int val, int pos) {
    if (tr[pos].l != tr[pos].r) {
        tr[pos << 1].mx += tr[pos].lz;
        tr[pos << 1].lz += tr[pos].lz;

        tr[pos << 1 | 1].mx += tr[pos].lz;
        tr[pos << 1 | 1].lz += tr[pos].lz;

        tr[pos].lz = 0;
    }

    if (tr[pos].l == l && tr[pos].r == r) {
        tr[pos].mx += val;
        tr[pos].lz += val;
        return;
    }

    int mid = tr[pos << 1].r;
    if (r <= mid) {
        update(l, r, val, pos << 1);
    } else if (mid < l) {
        update(l, r, val, pos << 1 | 1);
    } else {
        update(l, mid, val, pos << 1);
        update(mid + 1, r, val, pos << 1 | 1);
    }

    tr[pos].mx = max(tr[pos << 1].mx, tr[pos << 1 | 1].mx);
}

int query(int l, int r, int pos) {
    //cout << "Query " << l << " " << r << " at " << pos << " [" << tr[pos].l << ", " << tr[pos].r << "]" << endl;
    if (tr[pos].l != tr[pos].r) {
        tr[pos << 1].mx += tr[pos].lz;
        tr[pos << 1].lz += tr[pos].lz;

        tr[pos << 1 | 1].mx += tr[pos].lz;
        tr[pos << 1 | 1].lz += tr[pos].lz;

        tr[pos].lz = 0;
    }

    if (tr[pos].l == l && tr[pos].r == r) {
        return tr[pos].mx;
    }

    int mid = tr[pos << 1].r;
    if (r <= mid) {
        return query(l, r, pos << 1);
    } else if (mid < l) {
        return query(l, r, pos << 1 | 1);
    } else {
        return max(
                query(l, mid, pos << 1),
                query(mid + 1, r, pos << 1 | 1));
    }
}

vector<int> toys[MAXN];
void testcase() {
    for (int a = 0; a < MAXN; a++) {
        toys[a].clear();
        toys[a].push_back(0);
    }

    int N, S;
    cin >> N >> S;

    build (0, N, 1);

    int ans = 0;
    for (int a = 1; a <= N; a++) {
        int x;
        cin >> x;

        update (1, a, 1, 1);

        toys[x].push_back(a);

        // 1 back = toys[x].size() - 1
        // S back = toys[x].size() - S
        if ((int)toys[x].size() - 1 > S) {
            int sz = toys[x].size();
            update(toys[x][sz - S - 2] + 1, toys[x][sz - S - 1], -S, 1);
            update(1, toys[x][sz - S - 1], -1, 1);
        }
        /*
        for (int b = 1; b <= a; b++) {
            cout << query(b, b, 1) << " ";
        }
        cout << endl;
        */
        ans = max(ans, query(1, a, 1));
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    for (int a = 1; a <= T; a++) {
        cout << "Case #" << a << ": ";
        testcase();
    }
}
