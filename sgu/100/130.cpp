#include<bits/stdc++.h>
 
using namespace std;
 
#define allof(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int MAXN = 66;
 
ll dp[MAXN];
ll solve (int n) {
    if (dp[n] != -1) return dp[n];
 
    ll ans = 0;
    for (int a = 2; a <= n; a += 2) {
        ans += solve(a - 2) * solve (n - a);
    }
 
    return dp[n] = ans;
}
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
 
    memset(dp, -1, sizeof dp);
 
    dp[0] = 1;
    dp[2] = 1;
 
    int k;
    cin >> k;
 
    cout << solve(2 * k) << " " << k + 1;
}
