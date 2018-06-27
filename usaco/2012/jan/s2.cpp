#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 20;
const int MAXS = 105;

int N;

bitset<MAXN * MAXS> dp[MAXN + 1][MAXN * MAXS];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    dp[0][0][0] = true;

    int tot = 0;

    cin >> N;
    for(int a = 0; a < N; a++){
        int val;
        cin >> val;
        tot += val;

        for(int b = 0; b <= a * MAXS; b++){
            dp[a + 1][b] |= dp[a][b];
            dp[a + 1][b] |= dp[a][b] << val;
            dp[a + 1][b + val] |= dp[a][b];
        }
    }

    int ans = 1e9;
    for(int a = 0; a <= N * MAXS; a++){
        for(int b = 0; b <= N * MAXS; b++){
            if(dp[N][a][b]){
                ans = min(ans, max(max(a, b), tot - a - b));
            }
        }
    }
    
    cout << ans << "\n";
}
