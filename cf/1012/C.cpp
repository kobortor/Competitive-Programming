#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

int N;
int ht[MAXN];

//dist since last used
int dp[MAXN][MAXN / 2][3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    ht[0] = +1e9;
    for(int a = 1; a <= N; a++){
        cin >> ht[a];
    }

    memset(dp, 0x3f, sizeof dp);
    dp[1][0][2] = 0;
    dp[1][1][0] = 0;

    dp[2][0][2] = 0;
    dp[2][1][0] = max(0, ht[1] - (ht[2] - 1));
    dp[2][1][1] = max(0, ht[2] - (ht[1] - 1));

    for(int a = 3; a <= N; a++){
        for(int b = 0; 2 * b - 1 <= N; b++){
            dp[a][b][2] = min(dp[a][b][2], dp[a - 1][b][1]);
            dp[a][b][2] = min(dp[a][b][2], dp[a - 1][b][2]);

            dp[a][b][1] = min(dp[a][b][1], dp[a - 1][b][0] + max(0, ht[a] - (ht[a - 1] - 1)));
        }

        for(int b = 1; 2 * b - 1 <= N; b++){
            dp[a][b][0] = min(dp[a][b][0], dp[a - 1][b - 1][1] + max(0, min(ht[a - 1], ht[a - 2] - 1) - (ht[a] - 1)));
            dp[a][b][0] = min(dp[a][b][0], dp[a - 1][b - 1][2] + max(0, ht[a - 1] - (ht[a] - 1)));
        }
    }

    for(int a = 1; 2 * a - 1 <= N; a++){
        cout << *min_element(dp[N][a], dp[N][a] + 3) << " ";
    }
}
