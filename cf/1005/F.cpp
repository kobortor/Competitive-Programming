#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M, K;

vector<pii> adj[MAXN];
int dist[MAXN];

vector<string> ans;
string cursoln;

void solve(int pos){
    if(pos == N + 1){
        ans.push_back(cursoln);
        return;
    }

    for(pii p : adj[pos]){
        cursoln[p.second] = '1';
        solve(pos + 1);
        cursoln[p.second] = '0';

        if((int)ans.size() == K){
            break;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(dist, -1, sizeof dist);
    dist[1] = 0;

    cin >> N >> M >> K;

    for(int a = 1; a <= M; a++){
        cursoln += "0";
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, a - 1});
        adj[v].push_back({u, a - 1});
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int fr = q.front();
        q.pop();

        for(pii p : adj[fr]){
            if(dist[p.first] == -1){
                dist[p.first] = dist[fr] + 1;
                q.push(p.first);
            }
        }
    }

    for(int a = 1; a <= N; a++){
        for(int i = 0; i < (int)adj[a].size(); i++){
            if(dist[adj[a][i].first] != dist[a] - 1){
                swap(adj[a][i], adj[a].back());
                adj[a].pop_back();
                i--;
            }
        }
    }

    solve(2);

    cout << ans.size() << "\n";
    for(string str : ans){
        cout << str << "\n";
    }
}
