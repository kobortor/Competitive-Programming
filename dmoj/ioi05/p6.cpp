#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;
const int MAXK = 55;

int N, K;

ll dp[MAXN][MAXN][MAXK];

vector<int> adj[MAXN];
pll par[MAXN];
int trees[MAXN];

void dfs(int pos){
    for(int i : adj[pos]){
        dfs(i);
    }

    vector<ll> tmp(MAXK);

    int curlvl = 0;
    int curpar = pos;
    int curlen = 0;

    while(true){
        fill(dp[pos][curlvl], dp[pos][curlvl] + MAXK, (ll)curlen * trees[pos]);

        for(int i : adj[pos]){
            fill(allof(tmp), 1e18);
            for(int j = 0; j < MAXK; j++){
                for(int k = 0; k <= j; k++){
                    tmp[j] = min(tmp[j], dp[pos][curlvl][j - k] + dp[i][curlvl + 1][k]);
                }
                for(int k = 0; k < j; k++){
                    tmp[j] = min(tmp[j], dp[pos][curlvl][j - (k + 1)] + dp[i][0][k]);
                }
            }
            copy(allof(tmp), dp[pos][curlvl]);
        }

        if(curpar == 0){
            break;
        }

        curlvl++;
        curlen += par[curpar].second;
        curpar = par[curpar].first;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(dp, -1, sizeof dp);

    cin >> N >> K;

    for(int a = 1; a <= N; a++){
        cin >> trees[a];
        cin >> par[a].first >> par[a].second;

        adj[par[a].first].push_back(a);
    }

    dfs(0);

    cout << dp[0][0][K];
}
