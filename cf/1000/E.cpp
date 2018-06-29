#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

int N, M;
vector<int> adj[MAXN];

int cnt = 1;
int disc[MAXN];
int low[MAXN];

vector<int> stk;
int tp[MAXN];

void tarjan(int pos, int par){
    disc[pos] = low[pos] = cnt++;
    stk.push_back(pos);

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }

        if(!disc[i]){
            tarjan(i, pos);
            low[pos] = min(low[pos], low[i]);

            if(low[i] > disc[pos]){
                while(stk.back() != i){
                    tp[stk.back()] = i;
                    stk.pop_back();
                }
                tp[stk.back()] = i;
                stk.pop_back();
            }
        } else {
            low[pos] = min(low[pos], disc[i]);
        }
    }
}


vector<int> nadj[MAXN];

int ans = 0;

int path_dfs(int pos, int par){
    pii best = pii(0, 0);
    for(int i : nadj[pos]){
        if(i == par){
            continue;
        }

        int new_len = path_dfs(i, pos) + 1;
        if(new_len > best.first){
            best.second = best.first;
            best.first = new_len;
        } else if (new_len > best.second){
            best.second = new_len;
        }
    }

    ans = max(ans, best.first + best.second);
    return best.first;
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

    tarjan(1, -1);

    for(int a = 1; a <= N; a++){
        for(int i : adj[a]){
            if(tp[a] != tp[i]){
                nadj[tp[a]].push_back(tp[i]);
            }
        }
    }

    path_dfs(0, -1);

    cout << ans << "\n";
}
