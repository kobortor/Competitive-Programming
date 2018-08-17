#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;

int N, K, M;

int dep[MAXN];
int par[MAXN][20];
vector<pii> adj[MAXN];
bool special[MAXN];

priority_queue<pii, vector<pii>, greater<pii>> pq[MAXN];

void dfs(int pos){
    for(int a = 1; a < 20 && par[pos][a - 1] != -1; a++){
        par[pos][a] = par[par[pos][a - 1]][a - 1];
    }

    for(pii p : adj[pos]){
        if(!dep[p.first]){
            special[p.first] = p.second;
            dep[p.first] = dep[pos] + 1;
            par[p.first][0] = pos;
            dfs(p.first);
        }
    }
}

int dsu[MAXN];
int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int lca(int u, int v){
    if(dep[u] < dep[v]){
        swap(u, v);
    }

    for(int a = 0; a < 20; a++){
        if((dep[u] - dep[v]) & (1 << a)){
            u = par[u][a];
        }
    }

    if(u == v){
        return u;
    }

    for(int a = 19; a >= 0; a--){
        if(par[u][a] != par[v][a]){
            u = par[u][a];
            v = par[v][a];
        }
    }

    return par[u][0];
}

ll ans = 0;
void solve(int pos){
    for(pii p : adj[pos]){
        if(dep[p.first] < dep[pos]){
            continue;
        }

        solve(p.first);

        if(pq[p.first].size() > pq[pos].size()){
            pq[pos].swap(pq[p.first]);
        }
    }

    for(pii p : adj[pos]){
        if(dep[p.first] < dep[pos]){
            continue;
        }
        while(!pq[p.first].empty()){
            pq[pos].push(pq[p.first].top());
            pq[p.first].pop();
        }
    }

    while(!pq[pos].empty() && pq[pos].top().second >= dep[pos]){
        pq[pos].pop();
    }

    if(special[pos]){
        if(pq[pos].empty()){
            cout << -1;
            exit(0);
        } else {
            ans += pq[pos].top().first;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> M;

    for(int a = 1; a <= N; a++){
        dsu[a] = a;
    }

    while(K--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});

        int fu = find(u);
        int fv = find(v);
        dsu[fu] = fv;
    }

    memset(par, -1, sizeof par);

    vector<pair<int, pii>> remain;
    while(M--){
        int u, v, c;
        cin >> u >> v >> c;

        int fu = find(u);
        int fv = find(v);

        if(fu == fv){
            remain.push_back({c, {u, v}});
        } else {
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 0});
            dsu[fu] = fv;
        }
    }

    for(int a = 1; a <= N; a++){
        if(dep[a]){
            continue;
        }
        dep[a] = 1;
        dfs(a);
    }

    for(auto au : remain){
        int u, v, c;
        c = au.first;
        tie(u, v) = au.second;

        int l = lca(u, v);

        pq[u].push({c, dep[l]});
        pq[v].push({c, dep[l]});
    }

    for(int a = 1; a <= N; a++){
        if(dep[a] == 1){
            solve(a);
        }
    }

    cout << ans;
}
