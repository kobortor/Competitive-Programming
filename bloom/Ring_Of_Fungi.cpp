#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXH = 205;
const int MAXN = 30005;

int H, W, N;

int fungus_id = 0;
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

vector<int> adj;
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
                adj.push_back(fungus[p.first][p.second]);
            } else if (fungus[p.first][p.second] == 0){
                ring_dfs(p.first, p.second);
            }
        } else {
            adj.push_back(-1);
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
                adj.clear();
                ring_dfs(a, b);
                if(adj[0] != -1 && *min_element(allof(adj)) == *max_element(allof(adj))){
                    ans[adj[0]]++;
                }
            }
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
