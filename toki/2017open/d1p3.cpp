#include "beauty.h"
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

typedef pair<int, int> pii;

vector<int> adj[MAXN];
vector<int> nadj[MAXN];
int beauty[MAXN];
int cnt = 1;
int disc[MAXN], low[MAXN];
vector<vector<int>> groups;
vector<int> stk;
pii par[MAXN][20];

void tarjan(int pos, int PAR){
    disc[pos] = low[pos] = cnt++;
    stk.push_back(pos);

    for(int i : adj[pos]){
        if(i == PAR){
            continue;
        }
        if(disc[i] == 0){
            tarjan(i, pos);
            low[pos] = min(low[pos], low[i]);
            if(low[i] >= disc[pos]){
                vector<int> vec;
                while(stk.back() != i){
                    vec.push_back(stk.back());
                    stk.pop_back();
                }
                vec.push_back(stk.back());
                stk.pop_back();
                vec.push_back(pos);
                groups.push_back(vec);
            }
        } else {
            low[pos] = min(low[pos], disc[i]);
        }
    }
}

int dep[MAXN];
void dfs(int pos){
    for(int a = 0; a + 1 < 20 && par[pos][a].first != 0; a++){
        par[pos][a + 1].first = par[par[pos][a].first][a].first;
        par[pos][a + 1].second = max(par[pos][a].second, par[par[pos][a].first][a].second);
    }

    for(int i : nadj[pos]){
        if(i == par[pos][0].first){
            continue;
        }
        dep[i] = dep[pos] + 1;
        par[i][0] = {pos, beauty[i]};
        dfs(i);
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v]){
        swap(u, v);
    }

    int ans = 0;
    for(int a = 0; a < 20; a++){
        if((dep[u] - dep[v]) & (1 << a)){
            ans = max(ans, par[u][a].second);
            u = par[u][a].first;
        }
    }

    if(u == v){
        return max(ans, beauty[u]);
    }

    for(int a = 19; a >= 0; a--){
        if(par[u][a].first != par[v][a].first){
            ans = max(ans, par[u][a].second);
            ans = max(ans, par[v][a].second);

            u = par[u][a].first;
            v = par[v][a].first;
        }
    }
    ans = max(ans, par[u][0].second);
    ans = max(ans, par[v][0].second);

    u = par[u][0].first;
    v = par[v][0].first;

    return max(ans, beauty[u]);
}

vector<int> getMaximumBeauty(int N, int M, int Q, vector<int> T, vector<int> U, vector<int> V, vector<int> A, vector<int> B) {
    for(int a = 0; a < M; a++){
        adj[U[a]].push_back(V[a]);
        adj[V[a]].push_back(U[a]);
    }
    tarjan(1, -1);
    int extra = N + 1;
    for(vector<int> vec : groups){
        int best = 0;
        for(int i : vec){
            best = max(best, T[i - 1]);
            nadj[i].push_back(extra);
            nadj[extra].push_back(i);
        }

        beauty[extra] = best;
        extra++;
    }

    dfs(1);

    vector<int> ans;
    for(int a = 0; a < Q; a++){
        ans.push_back(lca(A[a], B[a]));
    }
    return ans;
}
