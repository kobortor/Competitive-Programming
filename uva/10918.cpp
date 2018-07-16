#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 35;

ll dp[MAXN][8];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    dp[1][0] = 1;
    for(int a = 1; a + 1 < MAXN; a++){
        dp[a + 1][0] += dp[a][4];
        dp[a + 1][0] += dp[a][1]; //vertical blocks

        dp[a + 1][1] += dp[a][0];
        dp[a + 1][4] += dp[a][0];

        for(int b = 0; b < 8; b++){
            dp[a + 1][b ^ 7] += dp[a][b];
        }
    }

    while(true){
        int n;
        cin >> n;
        if(n == -1){
            break;
        }

        cout << dp[n + 1][0] << "\n";
    }
}
