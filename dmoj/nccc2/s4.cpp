#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e4 + 5;

int ecnt = 1;
pii euler[MAXN];
vector<pii> adj[MAXN];

void euler_tour(int pos, int par){
    euler[pos].first = ecnt++;
    for(pii p : adj[pos]){
        if(p.second == par){
            continue;
        }
        euler_tour(p.second, pos);
    }
    euler[pos].second = ecnt - 1;
}

int ban[MAXN];

void ban_it(int src, int targ){
    if(euler[src] <= euler[targ]){
        ban[euler[targ].first]++;
        ban[euler[targ].second + 1]--;
    } else {
        ban[0]++;

        ban[euler[src].first]--;
        ban[euler[src].second + 1]++;
    }
}

int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N - 1; a++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    euler_tour(1, -1);

    for(int a = 1; a <= N; a++){
        sort(allof(adj[a]));
        for(int b = 1; b < (int)adj[a].size(); b++){
            if(adj[a][b].first == adj[a][b - 1].first){
                ban_it(a, adj[a][b].second);
                ban_it(a, adj[a][b - 1].second);
            }
        }
    }
    for(int a = 1; a <= N; a++){
        ban[a] += ban[a - 1];
    }

    vector<int> ans;
    for(int a = 1; a <= N; a++){
        if(!ban[euler[a].first]){
            ans.push_back(a);
        }
    }
    cout << ans.size() << "\n";
    for(int i : ans){
        cout << i << "\n";
    }
}
