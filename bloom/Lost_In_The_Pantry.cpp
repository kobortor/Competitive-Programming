#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 41;

int R, C, Rs, Cs, Re, Ce;
bool vis[MAXN][MAXN];
char grid[MAXN][MAXN];

int ans = 0;
void dfs(int r, int c){
    vis[r][c] = true;
    ans++;
    if(r == Re && c == Ce){
        cout << ans;
        exit(0);
    }

    vector<pii> dir = {{r, c - 1}, {r, c + 1}, {r - 1, c}, {r + 1, c}};
    for(pii p : dir){
        if( 0 <= p.first && p.first < R &&
            0 <= p.second && p.second < C &&
            grid[p.first][p.second] == grid[r][c] &&
            vis[p.first][p.second] == false){
            dfs(p.first, p.second);
        }
    }

    ans--;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> R >> C;
    for(int a = 0; a < R; a++){
        cin >> grid[a];
    }

    cin >> Rs >> Cs >> Re >> Ce;
    dfs(Rs, Cs);
}
