#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2505;
const ll mod = 1e9 + 7;

//[index][ '(' - ')' ]{min cost, num ways}
pll dp[MAXN][MAXN];
string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> str;

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = pll(0, 1);

    for(int a = 0; a < (int)str.size(); a++){
        for(int b = 0; b <= a; b++){
            if(str[a] == '('){
                //go up
                if(dp[a][b].first < dp[a + 1][b + 1].first){
                    dp[a + 1][b + 1].first = dp[a][b].first;
                    dp[a + 1][b + 1].second = dp[a][b].second;
                } else if (dp[a][b].first == dp[a + 1][b + 1].first){
                    dp[a + 1][b + 1].second = (dp[a + 1][b + 1].second + dp[a][b].second) % mod;
                }
                
                //go down
                if(b != 0){
                    if(dp[a][b].first + 1 < dp[a + 1][b - 1].first){
                        dp[a + 1][b - 1].first = dp[a][b].first + 1;
                        dp[a + 1][b - 1].second = dp[a][b].second;
                    } else if (dp[a][b].first + 1 == dp[a + 1][b - 1].first){
                        dp[a + 1][b - 1].second = (dp[a + 1][b - 1].second + dp[a][b].second) % mod;
                    }
                }
            } else {
                //go up
                if(dp[a][b].first + 1 < dp[a + 1][b + 1].first){
                    dp[a + 1][b + 1].first = dp[a][b].first + 1;
                    dp[a + 1][b + 1].second = dp[a][b].second;
                } else if (dp[a][b].first + 1 == dp[a + 1][b + 1].first){
                    dp[a + 1][b + 1].second = (dp[a + 1][b + 1].second + dp[a][b].second) % mod;
                }
                
                //go down
                if(b != 0){
                    if(dp[a][b].first < dp[a + 1][b - 1].first){
                        dp[a + 1][b - 1].first = dp[a][b].first;
                        dp[a + 1][b - 1].second = dp[a][b].second;
                    } else if (dp[a][b].first == dp[a + 1][b - 1].first){
                        dp[a + 1][b - 1].second = (dp[a + 1][b - 1].second + dp[a][b].second) % mod;
                    }
                }               
            }
        }
    }
    cout << dp[str.size()][0].first << " ";
    cout << dp[str.size()][0].second << " ";
}
