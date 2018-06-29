#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;

struct {
    int l, r;
    pii mn;
} tr[4 * MAXN];

int N, M;

int val[MAXN];
int cur[MAXN];
int lft[MAXN];

pair<pii, int> queries[MAXN];

int out[MAXN];

void pushup(int pos){
    tr[pos].mn = min(tr[pos << 1].mn, tr[pos << 1 | 1].mn);
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
        tr[pos].mn = pii(0x3f3f3f3f, val[l]);
    }
}

void update(int loc, int val, int pos){
    if(tr[pos].l == tr[pos].r){
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

pii query(int l, int r, int pos){
    if(tr[pos].l == l && tr[pos].r == r){
        return tr[pos].mn;
    }

    int mid = tr[pos << 1].r;
    if(r <= mid){
        return query(l, r, pos << 1);
    } else if (l > mid){
        return query(l, r, pos << 1 | 1);
    } else {
        return min(query(l, mid, pos << 1), query(mid + 1, r, pos << 1 | 1));
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> val[a];
        
        lft[a] = cur[val[a]];
        cur[val[a]] = a;
    }

    build(1, N, 1);

    cin >> M;

    for(int a = 1; a <= M; a++){
        cin >> queries[a].first.second >> queries[a].first.first;
        queries[a].second = a;
    }

    sort(queries + 1, queries + M + 1);

    int curr = 1;

    for(int a = 1; a <= M; a++){
        int l, r;
        tie(r, l) = queries[a].first;
        int id = queries[a].second;

        while(curr <= r){
            if(lft[curr]){
                update(lft[curr], 0x3f3f3f3f, 1);
            }
            update(curr, lft[curr], 1);
            curr++;
        }

        pii res = query(l, r, 1);
        if(res.first < l){
            out[id] = res.second;
        }
    }
    for(int a = 1; a <= M; a++){
        cout << out[a] << "\n";
    }
}
