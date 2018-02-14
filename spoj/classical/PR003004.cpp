#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

ll dp[20][2][10][200];

ll solve(ll val){
    string str = to_string(val);
    reverse(allof(str));
    while((int)str.size() < 19){
        str += '0';
    }
    reverse(allof(str));

    memset(dp, 0, sizeof dp);
    dp[0][1][0][0] = 1;
    for(int a = 0; a < (int)str.size(); a++){
        for(int b = 0; b < 10; b++){
            for(int c = 0; c < 10; c++){
                for(int t = 0; t < 185; t++){
                    if(c == str[a] - '0'){
                        dp[a + 1][1][c][t + c] += dp[a][1][b][t];
                    } else if (c < str[a] - '0') {
                        dp[a + 1][0][c][t + c] += dp[a][1][b][t];
                    }

                    dp[a + 1][0][c][t + c] += dp[a][0][b][t];
                }
            }
        }
    }

    ll ans = 0;
    for(int a = 0; a < 10; a++){
        for(int b = 0; b < 200; b++){
            ans += dp[str.size()][0][a][b] * b;
            ans += dp[str.size()][1][a][b] * b;
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        ll u, v;
        cin >> u >> v;
        if(!u){
            cout << solve(v) << "\n";
        } else {
            cout << solve(v) - solve(u - 1) << "\n";
        }
    }
}
