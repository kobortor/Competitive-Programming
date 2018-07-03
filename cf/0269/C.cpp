#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;
vector<pair<pii, int>> adj[MAXN];

bitset<MAXN> ans;
bitset<MAXN> vis;
int incoming[MAXN];
int tot[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 1; a <= M; a++){
        int u, v, c;
        cin >> u >> v >> c;

        adj[u].push_back({{v, c}, a});
        adj[v].push_back({{u, c}, -a});

        tot[u] += c;
        tot[v] += c;
    }

    queue<int> q;
    vis[1] = true;
    q.push(1);

    while(!q.empty()){
        int fr = q.front();
        q.pop();
        for(pair<pii, int> p : adj[fr]){
            int loc = p.first.first;
            int flo = p.first.second;
            int id = p.second;

            if(vis[loc]){
                continue;
            }

            ans[abs(id)] = id < 0;
            
            incoming[loc] += flo;
            if(loc != N && incoming[loc] * 2 == tot[loc]){
                vis[loc] = true;
                q.push(loc);
            }
        }
    }
    
    for(int a = 1; a <= M; a++){
        cout << ans[a] << "\n";
    }
}
