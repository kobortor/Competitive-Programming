#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int arr[MAXN];

struct {
    int l, r, mx, lz;
} tr[4 * MAXN];

void pushup(int pos){
    tr[pos].mx = max(tr[pos << 1].mx, tr[pos << 1 | 1].mx);
}

void pushdown(int pos){
    if(tr[pos].l == tr[pos].r){
        return;
    }

    tr[pos << 1].lz += tr[pos].lz;
    tr[pos << 1].mx += tr[pos].lz;

    tr[pos << 1 | 1].lz += tr[pos].lz;
    tr[pos << 1 | 1].mx += tr[pos].lz;

    tr[pos].lz = 0;
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
        tr[pos].mx = -l - 1;
    }
}

void update(int l, int r, int val, int pos){
    pushdown(pos);
    if(tr[pos].l == l && tr[pos].r == r){
        tr[pos].mx += val;
        tr[pos].lz += val;
        return;
    }

    int mid = tr[pos << 1].r;
    if(r <= mid){
        update(l, r, val, pos << 1);
    } else if (l > mid){
        update(l, r, val, pos << 1 | 1);
    } else {
        update(l, mid, val, pos << 1);
        update(mid + 1, r, val, pos << 1 | 1);
    }

    pushup(pos);
}

int query(int l, int r, int pos){
    pushdown(pos);
    if(tr[pos].l == l && tr[pos].r == r){
        return tr[pos].mx;
    }

    int mid = tr[pos << 1].r;
    if(r <= mid){
        return query(l, r, pos << 1);
    } else if (l > mid){
        return query(l, r, pos << 1 | 1);
    } else {
        return max(query(l, mid, pos << 1), query(mid + 1, r, pos << 1 | 1));
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("greedy.in", "r", stdin);
    freopen("greedy.out", "w", stdout);
    
    cin >> N;

    build(0, N, 1);

    for(int a = 1; a <= N; a++){
        if(query(0, a - 1, 1) >= 0){
            cout << N - a + 1;
            return 0;
        }

        int x;
        cin >> x;

        x = N - x - 1;

        update(x, N, 1, 1);
    }

    cout << 0;
}
