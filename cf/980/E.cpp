#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N, K;

vector<int> adj[MAXN];

int par[MAXN][22];

void dfs(int pos){
    for(int a = 1; a < 22; a++){
        if(par[pos][a-1] == -1) break;
        par[pos][a] = par[par[pos][a-1]][a-1];
    }
    for(int i : adj[pos]){
        if(i != par[pos][0]){
            par[i][0] = pos;
            dfs(i);
        }
    }
}

bool vis[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(par, -1, sizeof par);

    cin >> N >> K;
    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(N);
    vis[N] = true;

    int tot = 1;
    for(int a = N - 1; a >= 1; a--){
        if(vis[a]) continue;
        int cost = 1;
        int idx = a;
        for(int b = 21; b >= 0; b--){
            if(par[idx][b] != -1 && !vis[par[idx][b]]){
                cost += 1 << b;
                idx = par[idx][b];
            }
        }
        if(tot + cost + K <= N){
            tot += cost;
            idx = a;
            while(!vis[idx]){
                vis[idx] = true;
                idx = par[idx][0];
            }
        }
    }
    assert(tot + K == N);
    for(int a = 1; a <= N; a++){
        if(!vis[a]){
            cout << a << " ";
        }
    }
}
