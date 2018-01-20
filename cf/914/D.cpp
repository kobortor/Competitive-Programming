#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;

int gcd(int a, int b){
    while(a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

struct node {
    int l, r, val;
} tr[4 * MAXN];

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;
    tr[pos].val = 1;
    if(l == r){
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, pos << 1);
    build(mid + 1, r, pos << 1 | 1);
}

void update(int loc, int val, int pos){
    if(tr[pos].l == tr[pos].r){
        tr[pos].val = val;
        return;
    }
    int mid = tr[pos << 1].r;
    if(loc <= mid){
        update(loc, val, pos << 1);
    } else {
        update(loc, val, pos << 1 | 1);
    }
    tr[pos].val = gcd(tr[pos << 1].val, tr[pos << 1 | 1].val);
}

int query(int l, int r, int targ, int pos){
    if(tr[pos].l == tr[pos].r){
        int tmp_ans = tr[pos].val % targ == 0 ? r : r - 1;
        return tmp_ans;
    }
    if(tr[pos].l <= l && r <= tr[pos].r){
        if(tr[pos].val % targ == 0){
            return r;
        }
    }
    int mid = tr[pos << 1].r;
    if(r <= mid){
        int tmp_ans = query(l, r, targ, pos << 1);
        return tmp_ans;
    } else if (l > mid){
        int tmp_ans = query(l, r, targ, pos << 1 | 1);
        return tmp_ans;
    }
    int tmp = query(l, mid, targ, pos << 1);
    if(tmp == mid){
        int tmp_ans = query(mid + 1, r, targ, pos << 1 | 1);
        return tmp_ans;
    } else {
        return tmp;
    }
}

int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    build(1, N, 1);

    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        update(a, x, 1);
    }

    int Q;
    cin >> Q;
    while(Q--){
        int tp;
        cin >> tp;
        if(tp == 1){
            int l, r, x;
            cin >> l >> r >> x;
        
            int best = query(l, r, x, 1);
            if(best == r || best == r - 1){
                cout << "YES\n";
            } else if (query(best + 2, r, x, 1) == r) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            int i, y;
            cin >> i >> y;
            update(i, y, 1);
        }
    }
}
