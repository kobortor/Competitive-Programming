#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, Q;

vector<int> adj[MAXN];

int euler = 1;

int sz[MAXN];
int id[MAXN];
int ans[MAXN];

void dfs(int pos){
    id[pos] = euler;
    ans[euler++] = pos;
    sz[pos] = 1;

    for(int i : adj[pos]){
        dfs(i);
        sz[pos] += sz[i];
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;

    for(int a = 2; a <= N; a++){
        int par;
        cin >> par;
        adj[par].push_back(a);
    }
    
    dfs(1);

    while(Q--){
        int u, k;
        cin >> u >> k;

        if(k > sz[u]){
            cout << "-1\n";
        } else {
            cout << ans[id[u] + k - 1] << "\n";
        }
    }
}
