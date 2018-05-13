#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 75005;

int N, Q, K;

pii orig[MAXN];
pii sorted[MAXN];

struct node {
    int l, r, sum, lazy;
    int size(){
        return r - l + 1;
    }
} tr[MAXN * 4];

void pushdown(int pos){
    if(tr[pos].l != tr[pos].r && tr[pos].lazy != -1){
        int lft = min(tr[pos].lazy, tr[pos << 1].size());
        int rht = max(tr[pos].lazy - tr[pos << 1].size(), 0);
        
        tr[pos << 1].sum = lft;
        tr[pos << 1].lazy = lft;

        tr[pos << 1 | 1].sum = rht;
        tr[pos << 1 | 1].lazy = rht;

        tr[pos].lazy = -1;
    }
}

void pushup(int pos){
    tr[pos].sum = tr[pos << 1].sum + tr[pos << 1 | 1].sum;
}

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;
    tr[pos].sum = 0;
    tr[pos].lazy = -1;
    if(l != r){
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
    }
}

void update(int l, int r, int val, int pos){
    pushdown(pos);
    if(tr[pos].l == l && tr[pos].r == r){
        tr[pos].lazy = val;
        tr[pos].sum = val;
        return;
    }
    int mid = tr[pos << 1].r;
    if(r <= mid){
        update(l, r, val, pos << 1);
    } else if (l > mid) {
        update(l, r, val, pos << 1 | 1);
    } else {
        int lft = min(tr[pos << 1].r - l + 1, val);
        int rht = max(val - (tr[pos << 1].r - l + 1), 0);
        update(l, mid, lft, pos << 1);
        update(mid + 1, r, rht, pos << 1 | 1);
        pushup(pos);
    }
    pushup(pos);
}

int query(int l, int r, int pos){
    pushdown(pos);
    if(tr[pos].l == l && tr[pos].r == r){
        return tr[pos].sum;
    }
    int mid = tr[pos << 1].r;
    int ans = 0;
    if(r <= mid){
        ans += query(l, r, pos << 1);
    } else if (l > mid){
        ans += query(l, r, pos << 1 | 1);
    } else {
        ans += query(l, mid, pos << 1);
        ans += query(mid + 1, r, pos << 1 | 1);
    }
    pushup(pos);
    return ans;
}

pii sorts[MAXN];

pii stuff[MAXN];

//0 value at pos is below
//1 perfect
//2 value at pos is too high
int check(pii val){
    int kpos = -1;
    build(0, N - 1, 1);
    for(int a = 0; a < N; a++){
        if(orig[a] == val){
            kpos = a;
        } else if (orig[a] < val) {
            update(a, a, 1, 1);
        }
        stuff[a] = orig[a];
    }
    for(int a = 0; a < Q; a++){
        int l = sorts[a].first;
        int r = sorts[a].second;
        int sum = query(l, r, 1);
        update(l, r, sum, 1);
        if(l <= kpos && kpos <= r){
            kpos = l + sum;
        }
    }
    if(kpos == K){
        return 1;
    } else if (query(K, K, 1) == 1){
        return 0;
    } else {
        return 2;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q >> K;

    for(int a = 0; a < N; a++){
        cin >> orig[a].first;
        orig[a].second = a;
        sorted[a] = orig[a];
    }

    for(int a = 0; a < Q; a++){
        cin >> sorts[a].first;
        cin >> sorts[a].second;
    }

    sort(sorted, sorted + N);
    
    int lo = 0, hi = N - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int res = check(sorted[mid]);

        if(res == 1){
            cout << sorted[mid].first << endl;
            return 0;
        } else if (res == 0){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << sorted[lo].first << endl;
}
