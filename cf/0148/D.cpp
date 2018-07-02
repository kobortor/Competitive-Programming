#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

double dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int W, B;
    cin >> W >> B;

    for(int a = 0; a <= W; a++){
        for(int b = 0; b <= B; b++){
            if(a == 0){
                dp[a][b] = 0;
                continue;
            }

            if((a + b) % 3 == (W + B) % 3){
                dp[a][b] = (double)a / (a + b);
                if(b != 0){
                    dp[a][b] += (double)b / (a + b) * dp[a][b - 1];
                }
            } else if ((a + b + 1) % 3 == (W + B) % 3){
                double ans = (double)a / (a + b);

                double tmp = 0;
                if(b != 0){
                    if(b != 1){
                        //draws black twice
                        tmp += (double)(b - 1) / (a + b - 1) * dp[a][b - 2];
                    }

                    //draws black then white
                    tmp += (double)a / (a + b - 1) * dp[a - 1][b - 1];
                }

                ans += (1 - tmp) * b / (a + b);

                dp[a][b] = 1 - ans;
            }
        }
    }

    cout << fixed << setprecision(10) << dp[W][B];
}
