#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
const int MAXA = 1e5 + 5;

int R, C;
char grid[MAXN][MAXN];
int id[MAXN][MAXN]; //store the id of the water tank

vector<int> adj[MAXA];

void fill_dfs(int r, int c, int src){
    if(!isdigit(grid[r][c]) && grid[r][c] != '.'){
        id[r][c] = src;
        return;
    }
    if(id[r][c] != 0){
        return;
    }
    grid[r][c] = '.';
    id[r][c] = src;

    fill_dfs(r - 1, c, src);
    fill_dfs(r + 1, c, src);
    fill_dfs(r, c - 1, src);
    fill_dfs(r, c + 1, src);
}

int find_other(int r, int c, int pr, int pc){
    if(grid[r][c] != '+' && grid[r][c] != '-' && grid[r][c] != '|'){
        return -1;
    }
    if(id[r][c] != 0){
        return id[r][c];
    }

    int ans = 0;
    if(r - 1 != pr){
        ans = max(ans, find_other(r - 1, c, r, c));
    }
    if(r + 1 != pr){
        ans = max(ans, find_other(r + 1, c, r, c));
    }
    if(c - 1 != pc){
        ans = max(ans, find_other(r, c - 1, r, c));
    }
    if(c + 1 != pc){
        ans = max(ans, find_other(r, c + 1, r, c));
    }
    return ans;
}

void dfs(int pos){
    for(int i : adj[pos]){
        dfs(i);
    }
    cout << pos << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> R >> C;
    for(int a = 0; a <= C + 1; a++){
        grid[0][a] = '#';
        grid[R + 1][a] = '#';
    }
    for(int a = 1; a <= R; a++){
        cin >> (grid[a] + 1);
        grid[a][0] = '#';
        grid[a][C + 1] = '#';
    }

    for(int a = 1; a <= R; a++){
        for(int b = 1; b <= C; b++){
            if(isdigit(grid[a][b])) {
                string idstr;
                while(isdigit(grid[a][b])){
                    idstr += grid[a][b];
                    b++;
                }
                b--;
                fill_dfs(a, b, stoi(idstr));
            }
        }
    }

    for(int a = R; a >= 1; a--){
        for(int b = 1; b <= C; b++){
            if(id[a][b] && !id[a][b - 1] && grid[a][b - 1] == '-'){
                int other = find_other(a, b - 1, a, b);
                adj[id[a][b]].push_back(other);
            }
            if(id[a][b] && !id[a][b + 1] && grid[a][b + 1] == '-'){
                int other = find_other(a, b + 1, a, b);
                adj[id[a][b]].push_back(other);
            }
        }
    }
    dfs(1);
}
