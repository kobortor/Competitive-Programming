#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

const int MAXN = 1e5 + 5;

int N, M;

vector<int> adj[MAXN];
int incoming[MAXN];

bool vis[MAXN];

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1){
            ans = ans * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}

void init_dfs(int pos, vector<int> &nodes, vector<pii> &edges){
    vis[pos] = true;
    nodes.push_back(pos);
    for(int i : adj[pos]){
        if(i > pos){
            edges.push_back({pos, i});
        }
        if(!vis[i]){
            init_dfs(i, nodes, edges);
        }
    }
}

//[pos][pointed above]
ll dp[MAXN][2];
void solve_dfs(int pos){
    vis[pos] = true;

    dp[pos][1] = 1;

    vector<int> children;

    for(int i : adj[pos]){
        if(!vis[i]){
            solve_dfs(i);
            dp[pos][1] = dp[pos][1] * dp[i][1] % mod;
            
            children.push_back(i);
        }
    }

    dp[pos][0] = dp[pos][1];

    for(int i : children){
        dp[pos][0] = (dp[pos][0] + dp[pos][1] * qpow(dp[i][1], mod - 2) % mod * dp[i][0]) % mod;
    }
}

ll solve(int pos){
    vector<int> nodes;
    vector<pii> edges;

    init_dfs(pos, nodes, edges);

    if(nodes.size() == edges.size() + 1){
        //tree
        for(int i : nodes){
            vis[i] = false;
        }

        solve_dfs(pos);
        return dp[pos][0];
    } else if (nodes.size() == edges.size()){
        //pseudotree
        queue<int> q;
        for(int i : nodes){
            incoming[i] = adj[i].size();
            if(incoming[i] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int fr = q.front();
            q.pop();
            vis[fr] = false;

            for(int i : adj[fr]){
                incoming[i]--;
                if(incoming[i] == 1){
                    q.push(i);
                }
            }
        }

        ll ans = 2;
        for(int i : nodes){
            if(vis[i]){
                solve_dfs(i);
                ans = ans * dp[i][1] % mod;
            }
        }
        return ans;
    } else {
        return 0;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= M; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 1;
    for(int a = 1; a <= N; a++){
        if(!vis[a]){
            ans = ans * solve(a) % mod;
        }
    }

    cout << ans << "\n";
}
