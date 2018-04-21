#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

int N, M;
vector<int> adj[MAXN];

bool need_parent[MAXN];
bool vis[MAXN];
int chains = 0;

void dfs(int pos, int par){
    vis[pos] = need_parent[pos] = true;
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        dfs(i, pos);
        need_parent[pos] &= !need_parent[i];
    }
    if(need_parent[pos]){
        chains++;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> N >> M;
    while(M--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int a = 1; a <= N; a++){
        if(!vis[a]){
            dfs(a, -1);
        }
    }

    cout << min(N - 2, chains - 1);
}
