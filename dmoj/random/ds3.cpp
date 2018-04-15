#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
struct node {
    int l, r;
    int gcd, cnt, min;
} tr[MAXN * 4];

int gcd(int a, int b){
    while(a % b){
        a %= b;
        swap(a, b);
    }
    return b;
}

void pushup(int pos){
    tr[pos].gcd = gcd(tr[pos<<1].gcd, tr[pos<<1|1].gcd);
    tr[pos].min = min(tr[pos<<1].min, tr[pos<<1|1].min);
    tr[pos].cnt = 0;
    if(tr[pos].gcd == tr[pos<<1].gcd){
        tr[pos].cnt += tr[pos<<1].cnt;
    }
    if(tr[pos].gcd == tr[pos<<1|1].gcd){
        tr[pos].cnt += tr[pos<<1|1].cnt;
    }
}

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;
    tr[pos].gcd = 1;
    tr[pos].cnt = 0;
    tr[pos].min = -1;
    if(l != r){
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
    }
}

void update(int loc, int val, int pos){
    if(tr[pos].l == tr[pos].r){
        tr[pos].gcd = val;
        tr[pos].min = val;
        tr[pos].cnt = 1;
        return;
    }
    if(loc <= tr[pos << 1].r){
        update(loc, val, pos << 1);
    } else {
        update(loc, val, pos << 1 | 1);
    }
    pushup(pos);
}

pii query(int l, int r, int pos){
    if(tr[pos].l == l && tr[pos].r == r){
        return pii(tr[pos].gcd, tr[pos].cnt);
    }
    if(l > tr[pos << 1].r){
        return query(l, r, pos << 1 | 1);
    } else if (r <= tr[pos << 1].r){
        return query(l, r, pos << 1);
    } else {
        int mid = tr[pos << 1].r;
        pii p1 = query(l, mid, pos << 1);
        pii p2 = query(mid + 1, r, pos << 1 | 1);
        pii ans = pii(0, 0);
        ans.first = gcd(p1.first, p2.first);
        if(p1.first == ans.first){
            ans.second += p1.second;
        }
        if(p2.first == ans.first){
            ans.second += p2.second;
        }
        return ans;
    }
}

int querymin(int l, int r, int pos){
    if(tr[pos].l == l && tr[pos].r == r){
        return tr[pos].min;
    }
    if(l > tr[pos << 1].r){
        return querymin(l, r, pos << 1 | 1);
    } else if (r <= tr[pos << 1].r){
        return querymin(l, r, pos << 1);
    } else {
        int mid = tr[pos << 1].r;
        return min(querymin(l, mid, pos << 1), querymin(mid + 1, r, pos << 1 | 1));
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    build(1, N, 1);
    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        update(a, x, 1);
    }
    while(M--) {
        char tp;
        int a, b;
        cin >> tp >> a >> b;
        if(tp == 'C'){
            update(a, b, 1);
        } else if (tp == 'M'){
            cout << querymin(a, b, 1) << "\n";
        } else if (tp == 'G'){
            cout << query(a, b, 1).first << "\n";
        } else if (tp == 'Q'){
            cout << query(a, b, 1).second << "\n";
        }
    }
}
