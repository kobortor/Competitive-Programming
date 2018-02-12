#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

vector<int> adj[MAXN];
bool vis[MAXN];
void dfs(int pos){
    vis[pos] = true;
    for(int i : adj[pos]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

vector<pii> edges;
int N, M;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < M; a++){
        pii p;
        cin >> p.first >> p.second;
        edges.push_back(p);
    }
    for(int a = 0; a < M; a++){
        for(int b = 1; b <= N; b++){
            vis[b] = false;
            adj[b].clear();
        }
        vis[1] = true;

        for(int b = 0; b < M; b++){
            if(a != b){
                adj[edges[b].first].push_back(edges[b].second);
            }
        }
        dfs(1);

        cout << (vis[N] ? "YES" : "NO") << "\n";
    }
}
