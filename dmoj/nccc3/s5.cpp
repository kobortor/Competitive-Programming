#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 2e6 + 6;

struct node {
    int l, r;
    ll cost, cnt, lazy;
    bool clear_all = false;

    ll size(){
        return r - l + 1;
    }
} tr[4 * MAXV];

ll cost_to(ll x){
    return x * (x + 1) / 2;
}

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;
    tr[pos].cost = 0;
    tr[pos].cnt = 0;
    tr[pos].lazy = 0;

    if(l == r){
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, pos << 1);
    build(mid + 1, r, pos << 1 | 1);
}

void pushdown(int pos){
    if(tr[pos].l != tr[pos].r){
        if(tr[pos].clear_all){
            tr[pos << 1].cost = 0;
            tr[pos << 1].cnt = 0;
            tr[pos << 1].lazy = 0;
            tr[pos << 1].clear_all = true;

            tr[pos << 1 | 1].cost = 0;
            tr[pos << 1 | 1].cnt = 0;
            tr[pos << 1 | 1].lazy = 0;
            tr[pos << 1 | 1].clear_all = true;

            tr[pos].clear_all = false;
        }
        int mid = (tr[pos].l + tr[pos].r) / 2;
        ll cost1 = cost_to(mid) - cost_to(tr[pos].l - 1);
        ll cost2 = cost_to(tr[pos].r) - cost_to(mid);

        tr[pos << 1].cost += cost1 * tr[pos].lazy;
        tr[pos << 1].cnt += tr[pos << 1].size() * tr[pos].lazy;
        tr[pos << 1].lazy += tr[pos].lazy;
        
        tr[pos << 1 | 1].cost += cost2 * tr[pos].lazy;
        tr[pos << 1 | 1].cnt += tr[pos << 1 | 1].size() * tr[pos].lazy;
        tr[pos << 1 | 1].lazy += tr[pos].lazy;

        tr[pos].lazy = 0;
    }
}

void pushup(int pos){
    tr[pos].cnt = tr[pos << 1].cnt + tr[pos << 1 | 1].cnt;
    tr[pos].cost = tr[pos << 1].cost + tr[pos << 1 | 1].cost;
}

void update(int l, int r, int pos, ll cnt){
    pushdown(pos);
    if(tr[pos].l == l && tr[pos].r == r){
        ll cost = cost_to(r) - cost_to(l - 1);
        tr[pos].cost += cost * cnt;
        tr[pos].cnt += tr[pos].size() * cnt;
        tr[pos].lazy += cnt;
        tr[pos].clear_all = false;
        return;
    }
    int mid = tr[pos << 1].r;
    if(r <= mid){
        update(l, r, pos << 1, cnt);
    } else if (l > mid){
        update(l, r, pos << 1 | 1, cnt);
    } else {
        update(l, mid, pos << 1, cnt);
        update(mid + 1, r, pos << 1 | 1, cnt);
    }
    pushup(pos);
}

ll query_amnt(int pos, ll cash){
    pushdown(pos);
    if(tr[pos].cost <= cash){
        ll ans = tr[pos].cnt;
        tr[pos].cost = 0;
        tr[pos].cnt = 0;
        tr[pos].lazy = 0;
        tr[pos].clear_all = true;

        return ans;
    }
    if(tr[pos].l == tr[pos].r){
        ll ans = cash / tr[pos].l;
        tr[pos].cnt -= ans;
        tr[pos].cost -= ans * tr[pos].l;
        tr[pos].lazy -= ans;
        tr[pos].clear_all = false;

        return ans;
    }

    ll ans;
    if(tr[pos << 1].cost >= cash){
        ans = query_amnt(pos << 1, cash);
    } else {
        ll pcost = tr[pos << 1].cost;
        ans = query_amnt(pos << 1, cash) + query_amnt(pos << 1 | 1, cash - pcost);
    }
    pushup(pos);
    return ans;
}

ll query_low(int pos, ll remain){
    pushdown(pos);
    if(tr[pos].cnt <= remain){
        ll ans = tr[pos].cost;
        tr[pos].cost = 0;
        tr[pos].cnt = 0;
        tr[pos].lazy = 0;
        tr[pos].clear_all = true;

        return ans;
    }
    if(tr[pos].l == tr[pos].r){
        ll ans = tr[pos].l * remain;
        tr[pos].cnt -= remain;
        tr[pos].cost -= ans;
        tr[pos].lazy -= remain;
        tr[pos].clear_all = false;

        return ans;
    }

    ll ans;
    if(tr[pos << 1].cnt >= remain){
        ans = query_low(pos << 1, remain);
    } else {
        ll pcnt = tr[pos << 1].cnt;
        ans = query_low(pos << 1, remain) + query_low(pos << 1 | 1, remain - pcnt);
    }
    pushup(pos);
    return ans;
}

ll query_hi(int pos, ll remain){
    pushdown(pos);
    if(tr[pos].cnt <= remain){
        ll ans = tr[pos].cost;
        tr[pos].cost = 0;
        tr[pos].cnt = 0;
        tr[pos].lazy = 0;
        tr[pos].clear_all = true;

        return ans;
    }
    if(tr[pos].l == tr[pos].r){
        ll ans = tr[pos].l * remain;
        tr[pos].cnt -= remain;
        tr[pos].cost -= ans;
        tr[pos].lazy -= remain;
        tr[pos].clear_all = false;

        return ans;
    }

    ll ans;
    if(tr[pos << 1 | 1].cnt >= remain){
        ans = query_hi(pos << 1 | 1, remain);
    } else {
        ll pcnt = tr[pos << 1 | 1].cnt;
        ans = query_hi(pos << 1 | 1, remain) + query_hi(pos << 1, remain - pcnt);
    }
    pushup(pos);
    return ans;
}

ll query_nth(int pos, ll nth){
    pushdown(pos);
    if(tr[pos].cnt < nth){
        return -1;
    }
    if(tr[pos].l == tr[pos].r){
        return tr[pos].l;
    }

    ll ans;
    
    if(tr[pos << 1].cnt >= nth){
        ans = query_nth(pos << 1, nth);
    } else {
        ans = query_nth(pos << 1 | 1, nth - tr[pos << 1].cnt);
    }
    pushup(pos);
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    build(1, MAXV, 1);

    int N;
    cin >> N;
    
    while(N--){
        string oper;
        cin >> oper;
        if (oper == "ADD"){
            ll K, P;
            cin >> K >> P;
            update(P, P, 1, K);
        } else if(oper == "ADDRANGE"){
            ll A, B;
            cin >> A >> B;
            update(A, B, 1, 1);
        } else if(oper == "BUYAMT"){
            ll Q;
            cin >> Q;
            cout << query_amnt(1, Q) << "\n";
        } else if(oper == "BUYLOW"){
            ll L;
            cin >> L;
            cout << query_low(1, L) << "\n";           
        } else if(oper == "BUYHIGH"){
            ll L;
            cin >> L;
            cout << query_hi(1, L) << "\n";          
        } else if(oper == "COST"){
            ll L;
            cin >> L;
            cout << query_nth(1, L) << "\n";
        } else if(oper == "NUMCONES"){
            cout << tr[1].cnt << "\n";
        } else if(oper == "TOTALCOST"){
            cout << tr[1].cost << "\n";
        }
    }
}
