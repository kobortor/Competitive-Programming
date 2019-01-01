#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXH = 205;
const int MAXN = 30005;

int H, W, N;

int fungus_id = 0, extra_id = 0;
int fungus[MAXH][MAXH];
int ans[MAXN];

void fill_dfs(int r, int c){
    fungus[r][c] = fungus_id;
    vector<pii> nxt = {
        {r - 1, c - 1}, {r - 1, c}, {r - 1, c + 1},
        {r, c - 1}, {r, c + 1},
        {r + 1, c - 1}, {r + 1, c}, {r + 1, c + 1}};

    for(pii p : nxt){
        if (0 <= p.first && p.first < H &&
            0 <= p.second && p.second < W &&
            fungus[p.first][p.second] == -1){
            fill_dfs(p.first, p.second);
        }
    }
}

vector<int> adj[MAXN * 2];

void ring_dfs(int r, int c){
    fungus[r][c] = -1;
    vector<pii> nxt = {
        {r - 1, c - 1}, {r - 1, c}, {r - 1, c + 1},
        {r, c - 1}, {r, c + 1},
        {r + 1, c - 1}, {r + 1, c}, {r + 1, c + 1}};

    for(pii p : nxt){
        if (0 <= p.first && p.first < H &&
            0 <= p.second && p.second < W){
            if(fungus[p.first][p.second] >= 1){
                adj[fungus_id + extra_id].push_back(fungus[p.first][p.second]);
                adj[fungus[p.first][p.second]].push_back(fungus_id + extra_id);
            } else if (fungus[p.first][p.second] == 0){
                ring_dfs(p.first, p.second);
            }
        } else {
            adj[fungus_id + extra_id].push_back(0);
            adj[0].push_back(fungus_id + extra_id);
        }
    }
}

int dist[MAXN * 2];
void djikstra(){
    memset(dist, 0x3f, sizeof dist);

    queue<pii> q;
    q.push({0, 0});
    dist[0] = 0;

    while(!q.empty()){
        pii front = q.front();
        q.pop();
        for(int i : adj[front.first]){
            int change = (i <= fungus_id ? 1 : 0);
            if(front.second + change < dist[i]){
                dist[i] = front.second + change;
                q.push({i, dist[i]});
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> H >> W >> N;
    while(N--){
        int r, c;
        cin >> r >> c;
        fungus[r][c] = -1;
    }

    for(int a = 0; a < H; a++){
        for(int b = 0; b < W; b++){
            if(fungus[a][b] == -1){
                fungus_id++;
                fill_dfs(a, b);
            }
        }
    }

    for(int a = 0; a < H; a++){
        for(int b = 0; b < W; b++){
            if(fungus[a][b] == 0){
                extra_id++;
                ring_dfs(a, b);
            }
        }
    }

    for(int a = 0; a < H; a++){
        if(fungus[a][0] >= 1) {
            adj[fungus[a][0]].push_back(0);
            adj[0].push_back(fungus[a][0]);
        }
        if(fungus[a][W-1] >= 1) {
            adj[fungus[a][W-1]].push_back(0);
            adj[0].push_back(fungus[a][W-1]);
        }
    }

    for(int a = 0; a < W; a++){
        if(fungus[0][a] >= 1) {
            adj[fungus[0][a]].push_back(0);
            adj[0].push_back(fungus[0][a]);
        }
        if(fungus[H-1][a] >= 1) {
            adj[fungus[H-1][a]].push_back(0);
            adj[0].push_back(fungus[H-1][a]);
        }
    }

    djikstra();

    for(int a = 1; a <= extra_id; a++){
        int idx = fungus_id + a;
        if(find(allof(adj[idx]), 0) == adj[idx].end()){
            pii best = pii(dist[adj[idx][0]], adj[idx][0]);
            for(int i = 1; i < (int)adj[idx].size(); i++){
                best = min(best, pii(dist[adj[idx][i]], adj[idx][i]));
            }
            ans[best.second]++;
        }
    }

    if(fungus_id == 0){
        cout << "No colonies";
    }
    sort(ans + 1, ans + fungus_id + 1);
    for(int a = 1; a <= fungus_id; a++){
        cout << ans[a] << " ";
    }
}
