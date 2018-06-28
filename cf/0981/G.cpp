#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const ll mod = 998244353;

int N, Q;

struct node {
    int l, r;
    ll sum;
    ll lazyadd, lazymult;

    int size(){
        return r - l + 1;
    }
} tr[MAXN * 4];

void pushdown(int pos){
    if(tr[pos].l == tr[pos].r){
        return;
    }

    //multiplying

    ll mult = tr[pos].lazymult;
    tr[pos].lazymult = 1;

    tr[pos << 1].sum *= mult;
    tr[pos << 1].lazymult *= mult;
    tr[pos << 1].lazyadd *= mult;

    tr[pos << 1 | 1].sum *= mult;
    tr[pos << 1 | 1].lazymult *= mult;
    tr[pos << 1 | 1].lazyadd *= mult;

    //adding

    ll add = tr[pos].lazyadd;
    tr[pos].lazyadd = 0;

    tr[pos << 1].sum += add * tr[pos << 1].size();
    tr[pos << 1].lazyadd += add;

    tr[pos << 1 | 1].sum += add * tr[pos << 1 | 1].size();
    tr[pos << 1 | 1].lazyadd += add;

    //mods

    tr[pos << 1].sum %= mod;
    tr[pos << 1].lazyadd %= mod;
    tr[pos << 1].lazymult %= mod;

    tr[pos << 1 | 1].sum %= mod;
    tr[pos << 1 | 1].lazyadd %= mod;
    tr[pos << 1 | 1].lazymult %= mod;
}

void pushup(int pos){
    tr[pos].sum = (tr[pos << 1].sum + tr[pos << 1 | 1].sum) % mod;
}

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;
    tr[pos].sum = 0;
    tr[pos].lazyadd = 0;
    tr[pos].lazymult = 1;

    if(l != r){
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
    }
}

void update_sum(int l, int r, int pos){
    pushdown(pos);
    if(tr[pos].l == l && tr[pos].r == r){
        tr[pos].sum = (tr[pos].sum + tr[pos].size()) % mod;
        tr[pos].lazyadd = (tr[pos].lazyadd + 1) % mod;
        return;
    }

    int mid = tr[pos << 1].r;
    if(r <= mid){
        update_sum(l, r, pos << 1);
    } else if (l > mid){
        update_sum(l, r, pos << 1 | 1);
    } else {
        update_sum(l, mid, pos << 1);
        update_sum(mid + 1, r, pos << 1 | 1);
    }
    pushup(pos);
}

void update_prod(int l, int r, int pos){
    pushdown(pos);
    if(tr[pos].l == l && tr[pos].r == r){
        tr[pos].sum = (tr[pos].sum * 2) % mod;
        tr[pos].lazymult = (tr[pos].lazymult * 2) % mod;
        return;
    }

    int mid = tr[pos << 1].r;
    if(r <= mid){
        update_prod(l, r, pos << 1);
    } else if (l > mid){
        update_prod(l, r, pos << 1 | 1);
    } else {
        update_prod(l, mid, pos << 1);
        update_prod(mid + 1, r, pos << 1 | 1);
    }
    pushup(pos);
}

ll query(int l, int r, int pos){
    pushdown(pos);
    if(tr[pos].l == l && tr[pos].r == r){
        return tr[pos].sum;
    }

    int mid = tr[pos << 1].r;
    if(r <= mid){
        return query(l, r, pos << 1);
    } else if (l > mid){
        return query(l, r, pos << 1 | 1);
    } else {
        return (query(l, mid, pos << 1) + query(mid + 1, r, pos << 1 | 1)) % mod;
    }
}

set<pii> ranges[2][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;

    build(1, N, 1);
    
    for(int a = 1; a <= N; a++){
        ranges[0][a].insert(pii(1, N));

        ranges[0][a].insert(pii(-2, -2));
        ranges[1][a].insert(pii(-2, -2));
    }

    while(Q--){
        int tp;
        cin >> tp;
        if(tp == 1){
            int l, r, x;
            cin >> l >> r >> x;

            auto iter = prev(ranges[1][x].upper_bound(pii(l, MAXN)));
            if(iter->second < l) iter++;
            while(iter != ranges[1][x].end() && iter->first <= r){
                pii inter = pii(max(l, iter->first), min(r, iter->second));
                update_prod(inter.first, inter.second, 1);
                iter++;
            }

            vector<pii> todel, ins0, ins1;

            iter = prev(ranges[0][x].upper_bound(pii(l, MAXN)));
            if(iter->second < l) iter++;
            while(iter != ranges[0][x].end() && iter->first <= r){
                todel.push_back(*iter);

                pii inter = pii(max(l, iter->first), min(r, iter->second));

                ins1.push_back(inter);

                update_sum(inter.first, inter.second, 1);

                if(iter->first < l){
                    ins0.push_back(pii(iter->first, l - 1));
                }
                if(r < iter->second){
                    ins0.push_back(pii(r + 1, iter->second));
                }
                iter++;
            }

            for(pii p : todel){
                ranges[0][x].erase(p);
            }
            for(pii p : ins0){
                ranges[0][x].insert(p);
            }
            for(pii p : ins1){
                auto iter = ranges[1][x].lower_bound(p);
                if(iter != ranges[1][x].begin() && prev(iter)->second == p.first - 1){
                    p.first = prev(iter)->first;
                    ranges[1][x].erase(prev(iter));
                }
                if(iter != ranges[1][x].end() && iter->first == p.second + 1){
                    p.second = iter->second;
                    ranges[1][x].erase(iter);
                }
                ranges[1][x].insert(p);
            }
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 1) << "\n";
        }
    }
}
