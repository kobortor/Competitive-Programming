#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int R, C;
char grid[MAXN][MAXN];

vector<pii> hist;
void dfs(int r, int c){
    grid[r][c] = 'X';
    hist.push_back({r, c});
    if(r == R - 2 && c == C - 1){
        for(pii p : hist){
            cout << p.first << "," << p.second << endl;
        }
        exit(0);
    }
    vector<pii> nxt = {{r, c - 1}, {r, c + 1}, {r - 1, c}, {r + 1, c}};
    for(pii p : nxt){
        if(p.first < 0 || R <= p.first || p.second < 0 || C <= p.second || grid[p.first][p.second] == 'X'){
            continue;
        }
        dfs(p.first, p.second);
    }
    hist.pop_back();
    grid[r][c] = '_';
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> R >> C;
    for(int a = 0; a < R; a++){
        cin >> grid[a];
    }

    dfs(1, 0);
}
