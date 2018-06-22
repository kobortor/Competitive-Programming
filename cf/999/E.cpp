#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

int N, M, S;

vector<int> adj[MAXN];
vector<int> nadj[MAXN];
vector<pii> edges;

int cnt = 1, scccnt = 1;
int disc[MAXN];
int low[MAXN];
int scc[MAXN];
bool onstk[MAXN];

vector<int> stk;

void tarjan(int pos){
    disc[pos] = low[pos] = cnt++;
    stk.push_back(pos);
    onstk[pos] = true;

    for(int i : adj[pos]){
        if(!disc[i]){
            tarjan(i);
            low[pos] = min(low[pos], low[i]);
        } else if (onstk[i]){
            low[pos] = min(low[pos], disc[i]);
        }
    }

    if(disc[pos] == low[pos]){
        while(stk.back() != pos){
            scc[stk.back()] = scccnt;
            onstk[stk.back()] = false;
            stk.pop_back();
        }
        scc[stk.back()] = scccnt++;
        onstk[stk.back()] = false;
        stk.pop_back();
    }
}

bool root[MAXN];
bool vis[MAXN];
void dfs(int pos){
    vis[pos] = true;
    for(int i : nadj[pos]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> S;
    for(int a = 1; a <= M; a++){
        int u, v;
        cin >> u >> v;
        root[v] = false;
        adj[u].push_back(v);
    }

    for(int a = 1; a <= N; a++){
        if(!disc[a]){
            tarjan(a);
        }
    }

    scccnt--;

    memset(root, true, sizeof root);

    for(int a = 1; a <= N; a++){
        for(int i : adj[a]){
            if(scc[a] != scc[i]){
                nadj[scc[a]].push_back(scc[i]);
                root[scc[i]] = false;
            }
        }
    }

    dfs(scc[S]);

    int ans = 0;
    
    for(int a = 1; a <= scccnt; a++){
        if(!vis[a] && root[a]){
            dfs(a);
            ans++;
        }
    }

    cout << ans;
}
