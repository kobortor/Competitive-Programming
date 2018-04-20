#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
vector<int> adj[MAXN];

int cnt = 1;
int disc[MAXN], low[MAXN];

int bicnt = 1;
set<int> bicon[MAXN];
int bicsz[MAXN];

vector<int> stk;

void dfs(int pos, int par){
    disc[pos] = low[pos] = cnt++;
    stk.push_back(pos);
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        if(!disc[i]){
            dfs(i, pos);
            low[pos] = min(low[pos], low[i]);
            if(low[i] >= disc[pos]){
                while(stk.back() != i){
                    bicon[stk.back()].insert(bicnt);
                    bicsz[bicnt]++;
                    stk.pop_back();
                }
                bicon[i].insert(bicnt);
                bicsz[bicnt]++;
                stk.pop_back();

                bicon[pos].insert(bicnt);
                bicsz[bicnt]++;
                
                bicnt++;
            }
        } else {
            low[pos] = min(low[pos], disc[i]);
        }
    }
}

int biedge[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    vector<pii> edges;
    while(M--){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int a = 1; a <= N; a++){
        if(!disc[a]){
            dfs(a, -1);
        }
    }

    vector<int> ans;
    for(int a = 0; a < (int)edges.size(); a++){
        int u, v;
        tie(u, v) = edges[a];

        if(bicon[u].size() > bicon[v].size()){
            swap(u, v);
        }
        for(int i : bicon[u]){
            if(bicon[v].count(i)){
                biedge[i]++;
                break;
            }
        }
    }
    for(int a = 0; a < (int)edges.size(); a++){
        int u, v;
        tie(u, v) = edges[a];

        if(bicon[u].size() > bicon[v].size()){
            swap(u, v);
        }
        for(int i : bicon[u]){
            if(bicon[v].count(i)){
                if(biedge[i] == bicsz[i]){
                    ans.push_back(a + 1);
                }
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    for(int i : ans){
        cout << i << " ";
    }
    
}
