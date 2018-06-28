#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, M;

//-1 is unknown
//0 is lose
//1 is win
int dp[MAXN][MAXN][26];
vector<pii> adj[MAXN];

int lvl = 0;
bool dfs(int a, int b, int c){
    if(dp[a][b][c] != -1){
        return dp[a][b][c];
    }
    lvl++;
    dp[a][b][c] = false;

    for(pii p : adj[a]){
        if(p.second >= c){
            dp[a][b][c] |= !dfs(b, p.first, p.second);
        }
    }
    return dp[a][b][c];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= M; a++){
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c - 'a'});
    }
    memset(dp, -1, sizeof dp);
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            cout << char('A' + !dfs(a, b, 0));
        }
        cout << "\n";
    }
}
