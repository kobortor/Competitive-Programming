#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 20005;

int N;
vector<int> adj[MAXN];

pii best = {99999, 99999};

int dfs(int pos, int par){
    int sz = 1;
    int bal = 0;

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }

        int tmp = dfs(i, pos);
        bal = max(bal, tmp);
        sz += tmp;
    }

    bal = max(bal, N - sz);
    
    best = min(best, pii(bal, pos));

    return sz;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    cout << best.second << " " << best.first;
}
