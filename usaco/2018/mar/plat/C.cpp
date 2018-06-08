#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e4 + 5;

int N, M;
vector<pii> adj[MAXN];

int eid = 1;
pii euler[MAXN];
void euler_dfs(int pos, int par){
    euler[pos].first = eid++;
    for(pii p : adj[pos]){
        if(p.first != par){
            euler_dfs(p.first, pos);
        }
    }
    euler[pos].second = eid - 1;
}

multiset<int> paths[MAXN];
priority_queue<pii, vector<pii>, less<pii>> lft[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> rht[MAXN];

int ans[MAXN];

void solve_dfs(int pos, int par){
    for(pii p : adj[pos]){
        if(p.second == par){
            continue;
        }

        solve_dfs(p.first, p.second);

        if(lft[p.first].size() > lft[pos].size()){
            lft[p.first].swap(lft[pos]);
        }
        if(rht[p.first].size() > rht[pos].size()){
            rht[p.first].swap(rht[pos]);
        }
        if(paths[p.first].size() > paths[pos].size()){
            paths[p.first].swap(paths[pos]);
        }
    }

    for(pii p : adj[pos]){
        if(p.second == par){
            continue;
        }   
        while(!lft[p.first].empty()){
            lft[pos].push(lft[p.first].top());
            lft[p.first].pop();
        }
        while(!rht[p.first].empty()){
            rht[pos].push(rht[p.first].top());
            rht[p.first].pop();
        }
        
        paths[pos].insert(allof(paths[p.first]));
        paths[p.first].clear();
    }

    while(!lft[pos].empty() && euler[pos].first <= lft[pos].top().first){
        paths[pos].erase(paths[pos].find(lft[pos].top().second));
        lft[pos].pop();
    }

    while(!rht[pos].empty() && rht[pos].top().first <= euler[pos].second){
        paths[pos].erase(paths[pos].find(rht[pos].top().second));
        rht[pos].pop();
    }

    if(par != -1){
        if(paths[pos].empty()){
            ans[par] = -1;
        } else {
            ans[par] = *paths[pos].begin();
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);

    cin >> N >> M;
    for(int a = 1, u, v; a <= N - 1; a++){
        cin >> u >> v;
        adj[u].push_back(pii(v, a));
        adj[v].push_back(pii(u, a));
    }

    euler_dfs(1, -1);

    for(int a = 1; a <= M; a++){
        int u, v, c;
        cin >> u >> v >> c;

        if(euler[u].first < euler[v].first){
            rht[u].push(pii(euler[v].first, c));
            lft[v].push(pii(euler[u].first, c));
        } else {
            lft[u].push(pii(euler[v].first, c));
            rht[v].push(pii(euler[u].first, c));
        }

        paths[v].insert(c);
        paths[u].insert(c);           
    }

    solve_dfs(1, -1);
    for(int a = 1; a <= N - 1; a++){
        cout << ans[a] << "\n";
    }
}
