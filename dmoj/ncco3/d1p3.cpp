#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 35;

int N, M;

int grid[MAXN][MAXN];
vector<pii> adj[MAXN][MAXN];
bool vis[MAXN][MAXN];

void dfs(int r, int c, vector<pii> &vec){
    if(r < 0 || r >= N || c < 0 || c >= M) return;
    if(grid[r][c] == 0){
        vec.push_back(pii(r, c));
        return;
    }
    if(grid[r][c] == 2){
        return;
    }
    if(vis[r][c]) {
        return;
    }
    vis[r][c] = true;

    dfs(r - 1, c - 2, vec);
    dfs(r - 1, c + 2, vec);
    dfs(r + 1, c - 2, vec);
    dfs(r + 1, c + 2, vec);

    dfs(r - 2, c - 1, vec);
    dfs(r - 2, c + 1, vec);
    dfs(r + 2, c - 1, vec);
    dfs(r + 2, c + 1, vec);
}

int best[MAXN][MAXN];
ll cnt[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    int sr = 0, sc = 0;
    int dr = 0, dc = 0;

    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            cin >> grid[a][b];
            if(grid[a][b] == 3){
                sr = a;
                sc = b;
                grid[a][b] = 0;
            }
            if(grid[a][b] == 4){
                dr = a;
                dc = b;
                grid[a][b] = 0;
            }
        }
    }
    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            if(grid[a][b] != 0){
                continue;
            }
            memset(vis, false, sizeof vis);
            vector<pii> &vec = adj[a][b];
            vis[a][b] = true;
            dfs(a - 1, b - 2, vec);
            dfs(a - 1, b + 2, vec);
            dfs(a + 1, b - 2, vec);
            dfs(a + 1, b + 2, vec);

            dfs(a - 2, b - 1, vec);
            dfs(a - 2, b + 1, vec);
            dfs(a + 2, b - 1, vec);
            dfs(a + 2, b + 1, vec);

            sort(allof(vec));
            vec.erase(unique(allof(vec)), vec.end());
        }
    }

    memset(best, -1, sizeof best);
    best[sr][sc] = 0;
    cnt[sr][sc] = 1;
    
    int round = 0;
    while(cnt[dr][dc] == 0){
        if(round > 1000){
            cout << "-1\n";
            return 0;
        }
        for(int a = 0; a < N; a++){
            for(int b = 0; b < M; b++){
                if(best[a][b] == round){
                    for(pii p : adj[a][b]){
                        if(best[p.first][p.second] == -1 || best[p.first][p.second] == round + 1){
                            best[p.first][p.second] = round + 1;
                            cnt[p.first][p.second] += cnt[a][b];
                        }
                    }
                }
            }
        }
        round++;
    }
    cout << round - 1 << "\n";
    cout << cnt[dr][dc] << "\n";
}
