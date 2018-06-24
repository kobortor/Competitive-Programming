#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
vector<pii> adj[MAXN];

ll tot = 0;
int longest = 0;

void dfs(int pos, int par, int len){
    longest = max(longest, len);
    for(pii p : adj[pos]){
        if(p.first != par){
            dfs(p.first, pos, len + p.second);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N - 1; a++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});

        tot += c;
    }

    dfs(1, -1, 0);

    cout << 2 * tot - longest;
}
