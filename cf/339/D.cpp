#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1.5e5;

struct node {
    int l, r, val;
}tr[MAXN * 4];

void pushup(int pos){
    int len = tr[pos].r - tr[pos].l + 1;
    int lg2 = 0;
    while(len > 1){
        len >>= 1;
        lg2++;
    }
    if(lg2 % 2 == 1){
        tr[pos].val = (tr[pos << 1].val | tr[pos << 1 | 1].val);
    } else {
        tr[pos].val = (tr[pos << 1].val ^ tr[pos << 1 | 1].val);
    }
}

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;
    tr[pos].val = 0;

    if(l != r){
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
    }
}

void update(int loc, int val, int pos){
    if(tr[pos].l == tr[pos].r){
        tr[pos].val = val;
        return;
    }
    if(loc <= tr[pos << 1].r){
        update(loc, val, pos << 1);
    } else {
        update(loc, val, pos << 1 | 1);
    }
    pushup(pos);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;

    cin >> N >> M;
    
    build(1, 1 << N, 1);
    for(int a = 1; a <= (1 << N); a++){
        int x;
        cin >> x;
        update(a, x, 1);
    }
    while(M--){
        int p, b;
        cin >> p >> b;
        update(p, b, 1);
        cout << tr[1].val << "\n";
    }

}
