#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 7e4 + 4;

int N;
set<pii> adj[MAXN];

int best[MAXN];
bool solve2[MAXN];

void bfs(){
    memset(best, 0x3f, sizeof best);
    queue<int> q;
    for(int a = 1; a <= N; a++){
        if(adj[a].size() == 1){
            q.push(a);
            best[a] = 0;
        }
    }
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        for(pii p : adj[fr]){
            if(best[fr] + p.second < best[p.first]){
                best[p.first] = best[fr] + p.second;
                q.push(p.first);
            }
        }
    }
}

int dep = 0;
int ans = 0;
void dfs(int pos, int par){
    if(best[pos] <= dep){
        //cout << "Stop at " << pos << endl;
        ans++;
        return;
    }
    for(pii p : adj[pos]){
        if(p.first != par){
            dep += p.second;
            dfs(p.first, pos);
            dep -= p.second;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);

    cin >> N;
    for(int a = 0; a < N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].insert({v, 1});
        adj[v].insert({u, 1});
    }

    bfs();
    for(int a = 1; a <= N; a++){
        if((int)adj[a].size() == 2 && !solve2[a]){
            //merge those two
            vector<int> path2;

            int idx = adj[a].begin()->first;
            int par = a;
            while((int)adj[idx].size() == 2){
                path2.push_back(idx);
                int nxt = adj[idx].begin()->first == par ? next(adj[idx].begin())->first : next(adj[idx].begin())->first;
                par = idx;
                idx = nxt;
            }
            path2.push_back(idx);
            reverse(path2.begin(), path2.end());
            path2.push_back(a);

            idx = next(adj[a].begin())->first;
            par = a;
            
            while((int)adj[idx].size() == 2){
                path2.push_back(idx);
                int nxt = adj[idx].begin()->first == par ? next(adj[idx].begin())->first : next(adj[idx].begin())->first;
                par = idx;
                idx = nxt;
            }
            path2.push_back(idx);
            for(int i : path2){
                solve2[i] = true;
            }
            //path2 is now in order

            for(int b = 1; b + 1 < (int)path2.size(); b++){
                adj[path2[b]].clear();
                adj[path2[b]].insert(pii(path2[0], b));
                adj[path2[b]].insert(pii(path2.back(), path2.size() - b - 1));
            }

            adj[path2[0]].erase(pii(path2[1], 1));
            adj[path2.back()].erase(pii(path2[path2.size() - 2], 1));

            adj[path2[0]].insert(pii(path2.back(), path2.size() - 1));
            adj[path2.back()].insert(pii(path2[0], path2.size() - 1));
        }
    }
    for(int a = 1; a <= N; a++){
        //cout << "Testing " << a << endl;
        ans = 0;
        if((int)adj[a].size() == 2){
            pii p1 = *adj[a].begin();
            pii p2 = *next(adj[a].begin());
            dep = p1.second;
            dfs(p1.first, p2.first);

            dep = p2.second;
            dfs(p2.first, p1.first);

            dep = 0;
        } else {
            dfs(a, -1);
        }
        cout << ans << "\n";
    }
}
