#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int A, N, M;

vector<int> umbrellas[MAXN];
bool rain[MAXN];
ll dp[MAXN][MAXN];
ll wt[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> A >> N >> M;
    
    while(N--){
        int L, R;
        cin >> L >> R;
        for(int a = L + 1; a <= R; a++){
            rain[a] = true;
        }
    }
    
    for(int a = 1; a <= M; a++){
        int X;
        cin >> X >> wt[a];
        umbrellas[X].push_back(a);
    }
    
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i : umbrellas[0]){
        dp[0][i] = 0;
    }
    
    
    for(int a = 1; a <= A; a++){
        if(rain[a]){
            for(int b = 1; b <= M; b++) {
                dp[a][b] = min(dp[a][b], dp[a - 1][b] + wt[b]);
            }
        } else {
            for(int b = 0; b <= M; b++) {
                dp[a][b] = min(dp[a][b], dp[a - 1][b] + wt[b]);
            }
        }
        
        dp[a][0] = min(dp[a][0], *min_element(dp[a] + 1, dp[a] + M + 1));
        
        for(int i : umbrellas[a]){
            dp[a][i] = min(dp[a][i], dp[a][0]);
        }
    }
    
    if(dp[A][0] > 1e12){
        cout << -1;
    } else {
        cout << dp[A][0];
    }
}
