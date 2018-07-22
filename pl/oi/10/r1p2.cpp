#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M;

ll row[MAXN], col[MAXN];
ll dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> M >> N;
    for(int a = 0; a < M - 1; a++){
        cin >> row[a];
    }
    for(int a = 0; a < N - 1; a++){
        cin >> col[a];
    }

    sort(row, row + M);
    sort(col, col + N);

    reverse(row, row + M);
    reverse(col, col + N);

    memset(dp, 0x3f, sizeof dp);

    dp[0][0] = 0;

    for(int a = 0; a <= M - 1; a++){
        for(int b = 0; b <= N - 1; b++){
            if(a != M - 1){
                dp[a + 1][b] = min(dp[a + 1][b], dp[a][b] + row[a] * (b + 1));
            }
            if(b != N - 1){
                dp[a][b + 1] = min(dp[a][b + 1], dp[a][b] + col[b] * (a + 1));
            }
        }
    }

    cout << dp[M - 1][N - 1];
}
