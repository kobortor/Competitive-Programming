#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, Q;

struct node {
    int l, r;
    array<ll, 4> data; //min, max, best, sum
} tr[MAXN * 4];

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;
    if(l != r){
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
    }
}

array<ll, 4> merge(const array<ll, 4> &lft, const array<ll, 4> &rht){
    array<ll, 4> ans;
    ans[0] = min(lft[0], lft[3] + rht[0]);
    ans[1] = max(lft[1], lft[3] + rht[1]);
    ans[2] = max(lft[2], rht[2]);
    ans[2] = max(ans[2], rht[1] + lft[3] - lft[0]);
    ans[3] = lft[3] + rht[3];

    return ans;
}

void update(int loc, int val, int pos){
    if(tr[pos].l == tr[pos].r){
        tr[pos].data[0] = min(0, val);
        tr[pos].data[1] = val;
        tr[pos].data[2] = val; //empty array not allowed
        tr[pos].data[3] = val;
        return;
    }
    if(loc <= tr[pos<<1].r){
        update(loc, val, pos << 1);
    } else {
        update(loc, val, pos << 1 | 1);
    }
    
    tr[pos].data = merge(tr[pos << 1].data, tr[pos << 1 | 1].data);
}

array<ll, 4> query(int l, int r, int pos){
    if(tr[pos].l == l && tr[pos].r == r){
        return tr[pos].data;
    }
    if(r <= tr[pos << 1].r){
        return query(l, r, pos << 1);
    } else if (l > tr[pos << 1].r){
        return query(l, r, pos << 1 | 1);
    } else {
        int mid = tr[pos << 1].r;
        return merge(query(l, mid, pos << 1), query(mid + 1, r, pos << 1 | 1));
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;

    build(1, N, 1);

    for(int a = 1; a <= N; a++){
        int di;
        cin >> di;
        update(a, di, 1);
    }

    while(Q--){
        char tp;
        int x, y;
        cin >> tp >> x >> y;
        if(tp == 'S'){
            update(x, y, 1);
        } else {
            cout << query(x, y, 1)[2] << "\n";
        }
    }
}
