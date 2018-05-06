#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;
vector<int> adj[MAXN];

bool vis[MAXN];
bool dfs(int pos){
    vis[pos] = true;

    bool good = (int)adj[pos].size() == 2;
    for(int i : adj[pos]){
        if(!vis[i]){
            good &= dfs(i);
        }
    }
    return good;
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

    int ans = 0;
    for(int a = 1; a <= N; a++){
        if(!vis[a] && dfs(a)){
            ans++;
        }
    }
    cout << ans;
}
