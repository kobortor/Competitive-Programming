#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
const ll mod = 1e9 + 7;

int steps[MAXN];

int bit_cnt(int x){
    int ans = 0;
    while(x){
        x -= x & -x;
        ans++;
    }
    return ans;
}

//[limited][digit][digit count]
ll dp[2][MAXN][MAXN];
void count_leq(const string &N, int num_bits){
    for(int a = 0; a <= (int)N.size(); a++){
        for(int sum = 0; sum <= num_bits; sum++){
            dp[0][a][sum] = 0;
            dp[1][a][sum] = 0;
        }
    }

    dp[1][0][0] = 1;
    for(int a = 0; a < (int)N.size(); a++){
        for(int sum = 0; sum <= num_bits; sum++){
            dp[0][a][sum] %= mod;
            dp[1][a][sum] %= mod;

            if(N[a] == '1'){
                dp[1][a + 1][sum + 1] += dp[1][a][sum];
                dp[0][a + 1][sum] += dp[1][a][sum];
            } else {
                dp[1][a + 1][sum] += dp[1][a][sum];
            }
            dp[0][a + 1][sum + 1] += dp[0][a][sum];
            dp[0][a + 1][sum] += dp[0][a][sum];
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    steps[1] = 0;
    for(int a = 2; a < MAXN; a++){
        steps[a] = steps[bit_cnt(a)] + 1;
    }
    string N;
    int K;
    cin >> N >> K;

    if(K == 0){
        cout << 1;
        return 0;
    } else if (K == 1) {
        cout << N.size() - 1;
    } else {
        count_leq(N, MAXN - 1);
        ll ans = 0;
        
        for(int a = 1; a < MAXN; a++){
            if(steps[a] == K - 1){
                ans += dp[0][N.size()][a];
                ans += dp[1][N.size()][a];
                ans %= mod;
            }
        }
        cout << ans % mod;
    }
}
