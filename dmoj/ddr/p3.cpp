#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N, M;

vector<int> adj[MAXN];
int dist[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < M; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dist, 0x3f, sizeof dist);

    int S, T;

    cin >> S >> T;

    queue<int> q;
    q.push(S);

    dist[S] = 0;

    while(!q.empty()){
        int fr = q.front();
        q.pop();

        for(int i : adj[fr]){
            if(dist[i] == 0x3f3f3f3f){
                dist[i] = dist[fr] + 1;
                q.push(i);
            }
        }
    }

    cout << M - dist[T] << "\n";
}
