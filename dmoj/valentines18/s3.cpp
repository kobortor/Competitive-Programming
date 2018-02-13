#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;
const ll mod = 1e9 + 7;

//[pos][end with][len]
ll dp[MAXN][MAXN][MAXN];

ll solve(ll N, ll K){
    if(K == 0){
        return 0;
    }
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for(int a = 1; a <= N; a++){
        for(int k = 0; k <= K; k++){
            for(int b = 0; b < a; b++){ 
                for(int c = 1; c <= a; c++){
                    if(c <= b){
                        dp[a][c][1] += dp[a - 1][b][k];
                        dp[a][c][1] %= mod;
                    } else {
                        dp[a][c][k + 1] += dp[a - 1][b][k];
                        dp[a][c][k + 1] %= mod;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int a = 1; a <= N; a++){
        for(int k = 1; k <= K; k++){
            ans += dp[N][a][k];
            ans %= mod;
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;
    cout << (solve(N, K) - solve(N, K - 1) + mod) % mod;
}
