#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
vector<pii> adj[MAXN];

bool vis[MAXN];
int dist[MAXN];

void dfs(int pos){
    vis[pos] = true;
    for(pii p : adj[pos]){
        if(!vis[p.first]){
            dist[p.first] = dist[pos] + p.second;
            dfs(p.first);
        } else if (dist[p.first] != dist[pos] + p.second) {
            cout << "No";
            exit(0);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < M; a++){
        int l, r, d;
        cin >> l >> r >> d;
        adj[l].push_back({r, d});
        adj[r].push_back({l, -d});
    }
    for(int a = 1; a <= N; a++){
        if(!vis[a]){
            dfs(a);
        }
    }
    cout << "Yes";
}
