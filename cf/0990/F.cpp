#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;

int val[MAXN];
bool vis[MAXN];
vector<pii> adj[MAXN];

int out[MAXN];

int dfs(int pos){
    vis[pos] = true;

    int sum = val[pos];

    for(pii p : adj[pos]){
        if(vis[p.first]){
            continue;
        }
        int res = dfs(p.first);
        if(p.second < 0){
            out[abs(p.second)] = -res;
        } else {
            out[abs(p.second)] = res;
        }

        sum += res;
    }

    return sum;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    
    for(int a = 1; a <= N; a++){
        cin >> val[a];
    }
    
    cin >> M;
    for(int a = 1; a <= M; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(pii(v, a));
        adj[v].push_back(pii(u, -a));
    }

    if(dfs(1) != 0){
        cout << "Impossible\n";
    } else {
        cout << "Possible\n";
        for(int a = 1; a <= M; a++){
            cout << out[a] << "\n";
        }
    }
}
