#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 205;

int dp[MAXN][MAXN];
int N;
int arr[MAXN];

#define gcd __gcd

//solving for (l, r)
//arr[l] and arr[r] are the endpoints that cannot be removed
int solve (int l, int r) {
    if (l + 1 > r - 1) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    dp[l][r] = 1000000000;
    int g = gcd(arr[l], arr[r]);
    for (int a = l + 1; a <= r - 1; a++) {
        dp[l][r] = min(dp[l][r], g + solve(l, a) + solve(a, r));
    }
    return dp[l][r];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    while (true) {
        cin >> N;
        if (N == 0) break;

        for (int a = 0; a < N; a++) {
            cin >> arr[a];
            arr[a + N] = arr[a];
        }
        memset(dp, -1, sizeof dp);

        int ans = 1e9;
        for (int a = 0; a < N; a++) {
            for (int b = 1; b < N; b++) {
                ans = min(ans, gcd(arr[a], arr[a + b]) + solve(a, a + b) + solve(a + b, a + N));
            }
        }

        cout << ans << "\n";
    }
}
