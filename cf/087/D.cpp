#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;

int dsu[MAXN];
int sz[MAXN];
int dep[MAXN];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

struct edge {
    int u, v, wt, id;
};

vector<edge> edges;

vector<int> adj[MAXN];

void dfs(int pos, int par){
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        dep[i] = dep[pos] + 1;
        dfs(i, pos);
    }
}

int wt_below[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        dsu[a] = a;
        sz[a] = 1;
    }

    for(int a = 1; a <= N - 1; a++){
        edge e;
        cin >> e.u >> e.v >> e.wt;
        e.id = a;
        edges.push_back(e);

        adj[e.u].push_back(e.v);
        adj[e.v].push_back(e.u);
    }

    dfs(1, -1);

    for(edge &e : edges){
        //e.u should be lower than e.v
        if(dep[e.u] < dep[e.v]){
            swap(e.u, e.v);
        }
    }

    sort(allof(edges), [](edge &e1, edge &e2){
        if(e1.wt == e2.wt){
            return dep[e1.u] > dep[e2.u];
        } else {
            return e1.wt < e2.wt;
        }
    });

    ll best = -1;
    vector<int> bestv;

    for(int i = 0; i < (int)edges.size(); i++){
        wt_below[edges[i].id] = sz[find(edges[i].u)];

        int fu = find(edges[i].u);
        int fv = find(edges[i].v);

        dsu[fu] = fv;
        sz[fv] += sz[fu];

        if(i == (int)edges.size() - 1 || edges[i].wt != edges[i + 1].wt){
            for(int j = i; j >= 0 && edges[j].wt == edges[i].wt; j--){
                ll above = sz[find(edges[j].u)] - wt_below[edges[j].id];
                ll ans = 2ll * wt_below[edges[j].id] * above;

                if(ans > best){
                    best = ans;
                    bestv.clear();
                }
                if(ans == best){
                    bestv.push_back(edges[j].id);
                }
            }
        }
    }

    sort(allof(bestv));

    cout << best << " " << bestv.size() << "\n";

    for(int i : bestv){
        cout << i << " ";
    }
}
