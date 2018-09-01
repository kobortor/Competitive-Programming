#include "radius.h"
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

struct segtree {
    struct node {
        int l, r, mx;
    } tr[MAXN * 4];

    void pushup(int pos){
        tr[pos].mx = max(tr[pos << 1].mx, tr[pos << 1 | 1].mx);
    }

    void build(int l, int r, int pos){
        tr[pos].l = l;
        tr[pos].r = r;
        tr[pos].mx = -1e9;

        if(l != r){
            int mid = (l + r) / 2;
            build(l, mid, pos << 1);
            build(mid + 1, r, pos << 1 | 1);
            pushup(pos);
        }
    }
    void update(int loc, int val, int pos){
        if(tr[pos].l == tr[pos].r){
            tr[pos].mx = val;
            return;
        }

        if(loc <= tr[pos << 1].r){
            update(loc, val, pos << 1);
        } else {
            update(loc, val, pos << 1 | 1);
        }
        pushup(pos);
    }
    int query(int l, int r, int pos){
        if(tr[pos].l == l && tr[pos].r == r){
            return tr[pos].mx;
        }

        int mid = tr[pos << 1].r;
        if(r <= mid){
            return query(l, r, pos << 1);
        } else if (l > mid){
            return query(l, r, pos << 1 | 1);
        } else {
            return max(query(l, mid, pos << 1), query(mid + 1, r, pos << 1 | 1));
        }
    }
} top, bot;

vector<int> adj[MAXN];
int best[MAXN][2];

void predfs(int pos, int par){
    best[pos][0] = best[pos][1] = 0;

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        predfs(i, pos);
        int val = best[i][0] + 1;
        if(val > best[pos][0]){
            best[pos][1] = best[pos][0];
            best[pos][0] = val;
        } else if (val > best[pos][1]){
            best[pos][1] = val;
        }
    }
}

int ans[MAXN];
void dfs(int pos, int par, int dep){
    if(pos != 1){
        int mid = (dep + 1) / 2;
        //cout << pos << " gets 1.." << mid << " and " << mid + 1 << ".." << dep - 1 << endl;
        ans[pos] = best[pos][0] + 1;
        ans[pos] = max(ans[pos], top.query(1, mid, 1));

        if(mid + 1 <= dep - 1){
            ans[pos] = max(ans[pos], bot.query(mid + 1, dep - 1, 1) + dep + 1);
        }
    }

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        bool tp = (best[i][0] + 1 == best[pos][0]);

        //cout << "Going " << pos << " -> " << i << " is " << best[pos][tp] << endl;
        top.update(dep, best[pos][tp] + dep - 1, 1);
        bot.update(dep, best[pos][tp] - dep, 1);

        dfs(i, pos, dep + 1);

        top.update(dep, -1e9, 1);
        bot.update(dep, -1e9, 1);
    }
}

vector<int> getRadius(int N, int Q, vector<int> U, vector<int> V, vector<int> A) {
    for(int a = 0; a < N - 1; a++){
        adj[U[a]].push_back(V[a]);
        adj[V[a]].push_back(U[a]);
    }

    top.build(1, N, 1);
    bot.build(1, N, 1);

    predfs(1, -1);
    dfs(1, -1, 1);

    vector<int> ret;
    for(int a = 0; a < Q; a++){
        ret.push_back(ans[A[a]]);
    }
    return ret;
}
