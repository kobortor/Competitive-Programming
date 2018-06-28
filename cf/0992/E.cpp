#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

ll arr[MAXN];

struct {
    int l, r, mx;
    ll sum = 0;
} tr[MAXN * 4];

void pushup(int pos){
    tr[pos].mx = max(tr[pos << 1].mx, tr[pos << 1 | 1].mx);
    tr[pos].sum = tr[pos << 1].sum + tr[pos << 1 | 1].sum;
}

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;
    if(l == r){
        tr[pos].mx = arr[l];
        tr[pos].sum = arr[l];
    } else {
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
        pushup(pos);
    }
}

int foundat;
pll find(int l, ll val, ll pos){
    if(tr[pos].r < l){
        return pll(0, -1);
    }

    if(l <= tr[pos].l && tr[pos].mx < val){
        return pll(tr[pos].sum, tr[pos].mx);
    }

    if(tr[pos].l == tr[pos].r){
        foundat = tr[pos].l;
        return pll(tr[pos].sum, tr[pos].mx);
    }

    int mid = tr[pos << 1].r;
    if(mid < l){
        pll res = find(l, val, pos << 1 | 1);

        return res;
    } else {
        pll res = find(l, val, pos << 1);
        if(res.second >= val){
            return res;
        } else {
            pll res2 = find(l, val, pos << 1 | 1);
            res2.first += res.first;
            res2.second = max(res.second, res2.second);

            return res2;
        }
    }
}

void update(int loc, int val, int pos){
    if(tr[pos].l == tr[pos].r){
        tr[pos].mx = tr[pos].sum = val;
        return;
    }
    int mid = tr[pos << 1].r;
    if(loc <= mid){
        update(loc, val, pos << 1);
    } else {
        update(loc, val, pos << 1 | 1);
    }
    pushup(pos);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N, Q;

    cin >> N >> Q;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    build(1, N, 1);

    for(int a = 1; a <= Q; a++){
        int pi, xi;
        cin >> pi >> xi;

        arr[pi] = xi;
        update(pi, xi, 1);
        
        if(arr[1] == 0){
            cout << "1\n";
            continue;
        }


        bool solved = false;

        int pos = 1;
        ll sum = 0;
        while(pos <= N){
            if(tr[1].mx < sum){
                break;
            }

            foundat = -1;
            pll res = find(pos, sum, 1);

            if(foundat == -1){
                break;
            }

            if(sum + res.first - res.second == res.second){
                solved = true;
                cout << foundat << "\n";
                break;
            } else {
                sum += res.first;
                pos = foundat + 1;
            }
        }
        if(!solved){
            cout << "-1\n";
        }
    }
}
