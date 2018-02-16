#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105; 
int N, M;
int getid(int r, int c){
    return r * M + c;
}
char grid[MAXN][MAXN];
vector<pii> adj[MAXN * MAXN];
bool good[MAXN][MAXN];
bool blocked[MAXN][MAXN];
int best[MAXN * MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        cin >> grid[a];
    }

    pii start;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            if(grid[a][b] == '.'){
                good[a][b] = true;
            }
            if(grid[a][b] == 'S'){
                start = pii(a, b);
                good[a][b] = true;
            }
        }
    }
    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            //make sure conveyor doesn't move into a wall
            if(grid[a][b] == 'L'){
                adj[getid(a, b)].push_back(pii(getid(a, b - 1), 0));
            }
            if(grid[a][b] == 'R'){
                adj[getid(a, b)].push_back(pii(getid(a, b + 1), 0));
            }
            if(grid[a][b] == 'U'){
                adj[getid(a, b)].push_back(pii(getid(a - 1, b), 0));
            }
            if(grid[a][b] == 'D'){
                adj[getid(a, b)].push_back(pii(getid(a + 1, b), 0));
            }
            if(grid[a][b] == 'C'){
                //make sure camera can't see initially
                for(int i = 0; grid[a - i][b] != 'W'; i++){
                    if(good[a - i][b]) blocked[a - i][b] = true;
                }
                for(int i = 0; grid[a + i][b] != 'W'; i++){
                    if(good[a + i][b]) blocked[a + i][b] = true;
                }
                for(int i = 0; grid[a][b - i] != 'W'; i++){
                    if(good[a][b - i]) blocked[a][b - i] = true;
                }
                for(int i = 0; grid[a][b + i] != 'W'; i++){
                    if(good[a][b + i]) blocked[a][b + i] = true;
                }
            }
        }
    }
    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            if(blocked[a][b]){
                grid[a][b] = 'W';
            }
        }
    }

    pii dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            if(grid[a][b] == '.' || grid[a][b] == 'S'){
                for(pii p : dir){
                    if(grid[a + p.first][b + p.second] != 'W'){
                        adj[getid(a, b)].push_back(pii(getid(a + p.first, b + p.second), 1));
                    }
                }
            }
        }
    }

    /*
    for(int a = 0; a < N * M; a++) {
        for(pii p : adj[a]) {
            cout << a << " leads to " << p.first << " " << p.second << endl;
        }
    }
    */
    
    memset(best, 0x3f, sizeof best);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    if(grid[start.first][start.second] != 'W'){
        best[getid(start.first, start.second)] = 0;
        pq.push(pii(0, getid(start.first, start.second)));
    }

    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();
        if(grid[top.second / M][top.second % M] == 'W' || grid[top.second / M][top.second % M] == 'C'){
            continue;
        }
        for(pii p : adj[top.second]){
            if(top.first + p.second < best[p.first]){
                best[p.first] = top.first + p.second;
                pq.push(pii(best[p.first], p.first));
            }
        }
    }

    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            if(good[a][b] && pii(a, b) != start){
                if(grid[a][b] == 'W' || best[getid(a, b)] == 0x3f3f3f3f){
                    cout << "-1\n";
                } else {
                    cout << best[getid(a, b)] << "\n";
                }
            }
        }
    }
}
