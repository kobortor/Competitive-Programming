#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M, H;
int upd[MAXN];

vector<int> adj[MAXN];

int cnt = 1, ans = 0;
int disc[MAXN], low[MAXN];

int scccnt = 1;
int scc[MAXN];
vector<int> nodes[MAXN];
vector<int> stk;
void dfs(int pos){
    disc[pos] = low[pos] = cnt++;
    stk.push_back(pos);

    for(int i : adj[pos]){
        if(!disc[i]){
            dfs(i);
            low[pos] = min(low[pos], low[i]);
            if(low[i] == disc[i]){
                while(stk.back() != i){
                    scc[stk.back()] = scccnt;
                    nodes[scccnt].push_back(stk.back());
                    stk.pop_back();
                }
                scc[stk.back()] = scccnt;
                nodes[scccnt].push_back(stk.back());
                stk.pop_back();

                scccnt++;
            }
        } else {
            low[pos] = min(low[pos], disc[i]);
        }
    }
}

bool has_out[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> H;
    for(int a = 1; a <= N; a++){
        cin >> upd[a];
    }
    while(M--){
        int u, v;
        cin >> u >> v;

        if ((upd[u] + 1) % H == upd[v]) {
            adj[u].push_back(v);
        }
        if ((upd[v] + 1) % H == upd[u]){
            adj[v].push_back(u);
        }
    }

    for(int a = 1; a <= N; a++){
        if(!disc[a]){
            dfs(a);
            for(int i : stk){
                scc[i] = scccnt;
                nodes[scccnt].push_back(i);
            }
            scccnt++;
            stk.clear();
        }
    }
    for(int a = 1; a <= N; a++){
        for(int i : adj[a]){
            if(scc[i] != scc[a]){
                has_out[scc[a]] = true;
            }
        }
    }

    pii ans = pii(1e9, 0);
    for(int a = 1; a < scccnt; a++){
        if(!has_out[a]){
            ans = min(ans, pii(nodes[a].size(), a));
        }
    }
    cout << ans.first << "\n";
    for(int i : nodes[ans.second]){
        cout << i << " ";
    }
}
