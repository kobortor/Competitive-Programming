#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 20;
const int MAXS = 101;

int N;

bitset<MAXN * MAXS> dp[MAXN * MAXS];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    dp[0][0] = true;

    int tot = 0;

    cin >> N;
    for(int a = 1; a <= N; a++){
        int val;
        cin >> val;
        tot += val;

        for(int b = a * MAXS - 1; b >= 0; b--){
            dp[b] |= dp[b];
            dp[b] |= dp[b] << val;
            if(b - val >= 0){
                dp[b] |= dp[b - val];
            }
        }
    }

    int ans = 0x3f3f3f3f;
    for(int a = 0; a <= N * MAXS; a++){
        for(int b = 0; b <= N * MAXS; b++){
            if(dp[a][b]){
                ans = min(ans, max(max(a, b), tot - a - b));
            }
        }
    }
    
    cout << ans << "\n";
}
