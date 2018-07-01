#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

ll dp[MAXN][4];

string grid[2];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> grid[0] >> grid[1];

    int N = grid[0].size();

    memset(dp, 0xaf, sizeof dp);
    dp[0][3] = 0;

    for(int a = 0; a < N; a++){
        ll prv = *max_element(dp[a], dp[a] + 4);

        dp[a + 1][3] = prv;

        if(grid[0][a] != 'X'){
            dp[a + 1][2] = max(dp[a + 1][2], prv);

            if(grid[1][a] != 'X'){
                dp[a + 1][1] = max(dp[a + 1][1], dp[a][0] + 1);
            }
            dp[a + 1][3] = max(dp[a + 1][3], dp[a][0] + 1);
        }

        if(grid[1][a] != 'X'){
            dp[a + 1][1] = max(dp[a + 1][1], prv);

            if(grid[0][a] != 'X'){
                dp[a + 1][2] = max(dp[a + 1][2], dp[a][0] + 1);
            }
            dp[a + 1][3] = max(dp[a + 1][3], dp[a][0] + 1);
        }

        if(grid[0][a] != 'X' && grid[1][a] != 'X'){
            dp[a + 1][0] = max(dp[a + 1][0], prv);

            dp[a + 1][3] = max(dp[a + 1][3], dp[a][0] + 1);
            dp[a + 1][3] = max(dp[a + 1][3], dp[a][1] + 1);
            dp[a + 1][3] = max(dp[a + 1][3], dp[a][2] + 1);
        }

/*
        for(int b = 0; b < 4; b++){
            if(dp[a + 1][b] < 0){
                cout << "-\t";
            } else {
                cout << dp[a + 1][b] << "\t";
            }
        }
        cout << grid[0][a] << grid[1][a] << endl;
*/
    }

    cout << *max_element(dp[N], dp[N] + 4);
}
