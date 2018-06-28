#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 30005;
const int MAXJ = 500;
const int OFFSET = 250;

int N, D;

int gem[MAXN];
int dp[MAXN][MAXJ];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> D;
    while(N--){
        int x;
        cin >> x;
        gem[x]++;
    }

    for(int a = 0; a < MAXN; a++){
        fill(dp[a], dp[a] + MAXJ, -1e9);
    }
    dp[0][OFFSET] = 0;

    int ans = 0;

    for(int a = 0; a <= 30000; a++){
        for(int b = 0; b < MAXJ; b++){
            if(dp[a][b] < 0) continue;
            int diff = b - OFFSET + D;
            if(diff <= 0) continue;
            if(a + diff > 30000){
                ans = max(ans, dp[a][b] + gem[a]);
            } else {
                if(0 < b - 1 && b - 1 < MAXJ){
                    dp[a + diff][b - 1] = max(dp[a + diff][b - 1], dp[a][b] + gem[a]);
                }

                if(0 < b && b < MAXJ){
                    dp[a + diff][b] = max(dp[a + diff][b], dp[a][b] + gem[a]);
                }

                if(0 < b + 1 && b + 1 < MAXJ){
                    dp[a + diff][b + 1] = max(dp[a + diff][b + 1], dp[a][b] + gem[a]);
                }
            }
        }
    }
    cout << ans;
}
