#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

const int lt = 0, gt = 1;

struct node {
    int l, r, mx;
} tr[8 * MAXN];

void build (int l, int r, int pos) {
    tr[pos].l = l;
    tr[pos].r = r;
    tr[pos].mx = -1;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;

    build(l, mid, pos << 1);
    build(mid + 1, r, pos << 1 | 1);
}

void update(int loc, int val, int pos) {
    if (tr[pos].l == tr[pos].r) {
        tr[pos].mx = val;
        return;
    }
    if (loc <= tr[pos << 1].r) {
        update(loc, val, pos << 1);
    } else {
        update(loc, val, pos << 1 | 1);
    }

    tr[pos].mx = max(tr[pos << 1].mx, tr[pos << 1 | 1].mx);
}

int maxquery(int l, int r, int pos) {
    if (tr[pos].l == l && tr[pos].r == r) {
        return tr[pos].mx;
    }

    int mid = tr[pos << 1].r;
    if (r <= mid) {
        return maxquery(l, r, pos << 1);
    } else if (mid < l) {
        return maxquery(l, r, pos << 1 | 1);
    } else {
        return max(
                maxquery(l, mid, pos << 1),
                maxquery(mid + 1, r, pos << 1 | 1));
    }
}

struct {
    int data[MAXN];
    void update(int pos, int val) {
        while (pos < MAXN) {
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos) {
        int ans = 0;
        while (pos) {
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
} bit;

int N, Q;
int arr[MAXN];
vector<pii> updates;
int ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    build(-2e5 + MAXN, 2e5 + MAXN, 1);

    cin >> N >> Q;
    for (int a = 0; a < N; a++) {
        cin >> arr[a];
        arr[a] *= 2;
    }

    for (int a = 0; a < Q; a++) {
        string tp;
        int val;
        cin >> tp >> val;
        if (tp == "<") {
            updates.push_back({lt, 2 * val - 1});
            update(2 * val - 1 + MAXN, a, 1);
        } else {
            updates.push_back({gt, 2 * val + 1});
            update(2 * val + 1 + MAXN, a, 1);
        }
    }

    //tm, id
    vector<pii> queries;
    for (int a = 0; a < N; a++) {
        if (arr[a] == 0) {
            queries.push_back({0, a});
        } else {
            int prvm = maxquery(-abs(arr[a]) + 1 + MAXN, abs(arr[a]) - 1 + MAXN, 1);
            if (prvm == -1) {
                prvm = 0;
            } else if (updates[prvm].first == lt) {
                arr[a] = abs(arr[a]);
            } else {
                arr[a] = -abs(arr[a]);
            }
            queries.push_back({prvm, a});
        }
    }

    int curtm = updates.size();
    sort(allof(queries));
    reverse(allof(queries));

    for (pii p : queries) {
        int tm = p.first;
        int id = p.second;

        if (arr[id] == 0) {
            ans[id] = 0;
            continue;
        }

        while (curtm > tm) {
            curtm--;
            if (updates[curtm].first == lt && updates[curtm].second > 0) {
                bit.update(updates[curtm].second, 1);
            } else if (updates[curtm].first == gt && updates[curtm].second < 0) {
                bit.update(-updates[curtm].second, 1);
            }
        }

        int flips = bit.query(MAXN - 1) - bit.query(abs(arr[id]) - 1);
        if (flips % 2) {
            ans[id] = -arr[id];
        } else {
            ans[id] = arr[id];
        }
    }

    for (int a = 0; a < N; a++) {
        cout << ans[a] / 2 << " ";
    }
}
