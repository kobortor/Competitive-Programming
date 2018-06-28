#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

ll N, X, Y;
vector<int> adj[MAXN];
ll sz[MAXN];

ll dfs(int pos, int par){
    sz[pos] = 1;
    ll res = 0;
    ll mult = 1;
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        ll tmp = dfs(i, pos);
        res += tmp;
        sz[pos] += sz[i];
        if(pos == X && tmp == 0){
            mult += sz[i];
        }
    }
    if(pos == Y){
        return sz[pos];
    }
    if(pos == X){
        return res * mult;
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> X >> Y;

    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << N * (N - 1) - dfs(X, -1);
}
