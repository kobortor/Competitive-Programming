#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N, Q;
int SQ;

struct {
    int l, r;
    pii mx, mn;
} tr[4 * MAXN];

int arr[MAXN];

pii merge_mx(pii p1, pii p2){
    if(p1.first > p2.first){
        return pii(p1.first, max(p1.second, p2.first));
    } else {
        return pii(p2.first, max(p1.first, p2.second));
    }
}

pii merge_mn(pii p1, pii p2){
    if(p1.first < p2.first){
        return pii(p1.first, min(p1.second, p2.first));
    } else {
        return pii(p2.first, min(p1.first, p2.second));
    }
}

void pushup(int pos){
    tr[pos].mx = merge_mx(tr[pos << 1].mx, tr[pos << 1 | 1].mx);
    tr[pos].mn = merge_mn(tr[pos << 1].mn, tr[pos << 1 | 1].mn);
}

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;

    if(l != r){
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);

        pushup(pos);
    } else {
        tr[pos].mx.first = arr[l];
        tr[pos].mx.second = -1;

        tr[pos].mn.first = arr[l];
        tr[pos].mn.second = 2e9;
    }
}

void update(int loc, int val, int pos){
    if(tr[pos].l == tr[pos].r){
        tr[pos].mx.first = val;
        tr[pos].mn.first = val;
        return;
    }

    if(loc <= tr[pos << 1].r){
        update(loc, val, pos << 1);
    } else {
        update(loc, val, pos << 1 | 1);
    }

    pushup(pos);
}

pii query_mx(int l, int r, int pos){
    if(tr[pos].l == l && tr[pos].r == r){
        return tr[pos].mx;
    }

    int mid = tr[pos << 1].r;
    if(r <= mid){
        return query_mx(l, r, pos << 1);
    } else if(l > mid) {
        return query_mx(l, r, pos << 1 | 1);
    } else {
        pii p1, p2;
        p1 = query_mx(l, mid, pos << 1);
        p2 = query_mx(mid + 1, r, pos << 1 | 1);

        return merge_mx(p1, p2);
    }
}

pii query_mn(int l, int r, int pos){
    if(tr[pos].l == l && tr[pos].r == r){
        return tr[pos].mn;
    }

    int mid = tr[pos << 1].r;
    if(r <= mid){
        return query_mn(l, r, pos << 1);
    } else if(l > mid) {
        return query_mn(l, r, pos << 1 | 1);
    } else {
        pii p1, p2;
        p1 = query_mn(l, mid, pos << 1);
        p2 = query_mn(mid + 1, r, pos << 1 | 1);

        return merge_mn(p1, p2);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;
    SQ = sqrt(N);

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    build(1, N, 1);

    int xorv = 0;

    while(Q--){
        int tp, l, r;
        cin >> tp >> l >> r;

        l ^= xorv;
        r ^= xorv;

        if(tp == 1){
            update(l, r, 1);
        } else if (tp == 2){
            pii res = query_mn(l * SQ - SQ + 1, r * SQ, 1);

            xorv = res.first + res.second;

            cout << xorv << "\n";
        } else {
            pii res = query_mx(l * SQ - SQ + 1, r * SQ, 1);

            xorv = res.first + res.second;

            cout << xorv << "\n";
        }
    }
}
