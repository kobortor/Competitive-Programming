#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const int MAXK = 105;

int N, M, K, S;

vector<int> src[MAXK];
vector<int> adj[MAXN];

int dp[MAXN][MAXK];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K >> S;

    for(int a = 1; a <= N; a++){
        int tp;
        cin >> tp;
        src[tp].push_back(a);
    }

    for(int a = 0; a < M; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, 0x3f, sizeof dp);
    
    for(int a = 1; a <= K; a++){
        queue<int> q;
        for(int i : src[a]){
            q.push(i);
            dp[i][a] = 0;
        }

        while(!q.empty()){
            int fr = q.front();
            q.pop();
            for(int i : adj[fr]){
                if(dp[fr][a] + 1 < dp[i][a]){
                    dp[i][a] = dp[fr][a] + 1;
                    q.push(i);
                }
            }
        }
    }

    for(int a = 1; a <= N; a++){
        nth_element(dp[a] + 1, dp[a] + 1 + S, dp[a] + 1 + K);

        int ans = 0;
        for(int b = 1; b <= S; b++){
            ans += dp[a][b];
        }
        cout << ans << " ";
    }
}
