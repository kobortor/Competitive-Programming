#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, Q;

struct edge {
    int u, v, c;
    bool operator<(const edge &e) const {
        return c < e.c;
    }
}edges[MAXN];

struct query{
    int id, vi, Ki;
    bool operator<(const query &q) const {
        return Ki < q.Ki;
    }
}queries[MAXN];

int dsu[MAXN];
int sz[MAXN];
int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int out[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    cin >> N >> Q;

    for(int a = 1; a <= N; a++){
        dsu[a] = a;
        sz[a] = 1;
    }

    for(int a = 0; a < N - 1; a++){
        cin >> edges[a].u;
        cin >> edges[a].v;
        cin >> edges[a].c;
    }
    sort(edges, edges + N - 1);
    reverse(edges, edges + N - 1);

    for(int a = 0; a < Q; a++){
        cin >> queries[a].Ki;
        cin >> queries[a].vi;
        queries[a].id = a;
    }
    sort(queries, queries + Q);
    reverse(queries, queries + Q);
    
    int id = 0;
    for(int a = 0; a < Q; a++){
        while(id < N - 1 && edges[id].c >= queries[a].Ki){
            int fu = find(edges[id].u);
            int fv = find(edges[id].v);
            if(fu != fv){
                dsu[fu] = fv;
                sz[fv] += sz[fu];
            }
            id++;
        }
        out[queries[a].id] = sz[find(queries[a].vi)] - 1;
    }
    for(int a = 0; a < Q; a++){
        cout << out[a] << "\n";
    }
}
