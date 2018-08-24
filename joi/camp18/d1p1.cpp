#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int cnt = 1;
vector<int> adj[MAXN];
int C[MAXN];
int par[MAXN];
int top[MAXN];
int id[MAXN];
int sz[MAXN];
int hvson[MAXN];

vector<int> queries;

void dfs1(int pos){
    hvson[pos] = -1;
    sz[pos] = 1;
    for(int i : adj[pos]){
        par[i] = pos;
        dfs1(i);
        sz[pos] += sz[i];
        if(hvson[pos] == -1 || sz[hvson[pos]] < sz[i]){
            hvson[pos] = i;
        }
    }
}

void dfs2(int pos, int tp){
    id[pos] = cnt++;
    top[pos] = tp;
    if(hvson[pos] != -1){
        dfs2(hvson[pos], tp);
    }

    for(int i : adj[pos]){
        if(i != hvson[pos]){
            dfs2(i, i);
        }
    }
}

struct {
    int l, r, val;
} tr[MAXN * 4];

void pushup(int pos){
    if(tr[pos << 1].val == tr[pos << 1 | 1].val){
        tr[pos].val = tr[pos << 1].val;
    } else {
        tr[pos].val = -1;
    }
}

void pushdown(int pos){
    if(tr[pos].l != tr[pos].r && tr[pos].val != -1){
        tr[pos << 1].val = tr[pos].val;
        tr[pos << 1 | 1].val = tr[pos].val;
    }
}

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;
    tr[pos].val = -1;

    if(l != r){
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
    }
}

void update(int l, int r, int val, int pos){
    pushdown(pos);
    if(tr[pos].l == l && tr[pos].r == r){
        tr[pos].val = val;
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

void query(int l, int r, int pos, vector<pii> &res){
    pushdown(pos);
    if(l <= tr[pos].l && tr[pos].r <= r && tr[pos].val != -1){
        if(!res.empty() && res.back().first == tr[pos].val){
            res.back().second += tr[pos].r - tr[pos].l + 1;
        } else {
            res.push_back(pii(tr[pos].val, tr[pos].r - tr[pos].l + 1));
        }
        return;
    }
    if(tr[pos].r < l || r < tr[pos].l){
        return;
    }
    query(l, r, pos << 1 | 1, res);
    query(l, r, pos << 1, res);
    pushup(pos);
}

struct BIT {
    int data[MAXN];
    void update(int pos, int val){
        while(pos < MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos){
        int ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
} ds;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    vector<int> uniq;
    for(int a = 1; a <= N; a++){
        cin >> C[a];
        uniq.push_back(C[a]);
    }

    sort(allof(uniq));
    uniq.erase(unique(allof(uniq)), uniq.end());
    for(int a = 1; a <= N; a++){
        C[a] = lower_bound(allof(uniq), C[a]) - uniq.begin() + 1;
    }

    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        queries.push_back(v);
    }

    dfs1(1);
    dfs2(1, 1);

    build(1, N, 1);

    for(int i : queries){
        vector<pii> res;

        int pos = par[i];
        while(pos){
            query(id[top[pos]], id[pos], 1, res);
            pos = par[top[pos]];
        }
        reverse(allof(res));

        ll ans = 0;
        int added = 0;
        for(pii p : res){
            ans += (ll)(added - ds.query(p.first)) * p.second;
            ds.update(p.first, p.second);
            added += p.second;
        }

        for(pii p : res){
            ds.update(p.first, -p.second);
        }

        pos = i;
        while(pos){
            update(id[top[pos]], id[pos], C[i], 1);
            pos = par[top[pos]];
        }

        cout << ans << endl;
    }
}
