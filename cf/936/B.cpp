#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;
vector<int> adj[MAXN];

bool vis[MAXN][2];
int par[MAXN][2];
int incoming[MAXN][2];

void dfs(int pos, bool tp){
    vis[pos][tp] = true;
    for(int i : adj[pos]){
        if(!vis[i][!tp]){
            par[i][!tp] = pos;
            dfs(i, !tp);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        int ci;
        cin >> ci;
        for(int b = 0; b < ci; b++){
            int x;
            cin >> x;
            adj[a].push_back(x);
        }
    }
    
    //petya is player 0

    int start;
    cin >> start;
    dfs(start, 0);

    for(int a = 1; a <= N; a++){
        if(adj[a].empty() && vis[a][1]){
            cout << "Win\n";
            int idx = a;
            bool tp = 1;
            vector<int> path;
            while(idx != start || tp){
                path.push_back(idx);
                idx = par[idx][tp];
                tp ^= 1;
            }
            path.push_back(start);
            while(!path.empty()) {
                cout << path.back() << " ";
                path.pop_back();
            }
            return 0;
        }
    }
    
    for(int a = 1; a <= N; a++){
        if(vis[a][0]){
            for(int i : adj[a]){
                incoming[i][1]++;
            }
        }
        if(vis[a][1]){
            for(int i : adj[a]){
                incoming[i][0]++;
            }
        }
    }
    if(incoming[start][0]){
        cout << "Draw";
        return 0;
    }
    queue<pii> q;
    q.push({start, 0});
    while(!q.empty()){
        pii fr = q.front();
        q.pop();
        for(int i : adj[fr.first]){
            incoming[i][!fr.second]--;
            if(!incoming[i][!fr.second]){
                q.push({i, !fr.second});
            }
        }
    }
    for(int a = 1; a <= N; a++){
        if(incoming[a][0] || incoming[a][1]){
            cout << "Draw";
            return 0;
        }
    }
    cout << "Lose";
}
