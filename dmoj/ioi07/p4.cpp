#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXK = 3;

int N;
int cur = 0;

int dp[2][4][4][4][4];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    memset(dp, 0xaf, sizeof dp);
    dp[0][0][0][0][0] = 0;

    for(int a = 1; a <= N; a++){
        char ch;
        cin >> ch;

        int tp;
        if(ch == 'M'){
            tp = 1;
        } else if (ch == 'F'){
            tp = 2;
        } else { //ch == 'B'
            tp = 3;
        }

        for(int h = 0; h < 4; h++){
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    for(int k = 0; k < 4; k++){
                        int add1 = 0, add2 = 0;

                        add1 += tp == 1 || h == 1 || i == 1;
                        add1 += tp == 2 || h == 2 || i == 2;
                        add1 += tp == 3 || h == 3 || i == 3;

                        add2 += tp == 1 || j == 1 || k == 1;
                        add2 += tp == 2 || j == 2 || k == 2;
                        add2 += tp == 3 || j == 3 || k == 3;

                        dp[!cur][tp][h][j][k] = max(dp[!cur][tp][h][j][k], dp[cur][h][i][j][k] + add1);
                        dp[!cur][h][i][tp][j] = max(dp[!cur][h][i][tp][j], dp[cur][h][i][j][k] + add2);

                        dp[cur][h][i][j][k] = 0xafafafaf;
                    }
                }
            }
        }

        cur ^= 1;
    }

    int best = 0;

    for(int h = 0; h < 4; h++){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    best = max(best, dp[cur][h][i][j][k]);
                }
            }
        }
    }

    cout << best;
}
