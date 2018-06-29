#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

const int MAXN = 1005;

int nck[MAXN][MAXN];
int N;
int arr[MAXN];
int dp[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    nck[0][0] = 1;
    for(int a = 1; a < MAXN; a++){
        nck[a][0] = 1;
        for(int b = 1; b <= a; b++){
            nck[a][b] = (nck[a - 1][b - 1] + nck[a - 1][b]) % mod;
        }
    }

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }

    dp[N] = 1;
    for(int a = N - 1; a >= 0; a--){
        if(arr[a] <= 0){
            continue;
        }
        if(arr[a] > N){
            continue;
        }

        for(int b = 1; a + b <= N; b++){
            dp[a] = ((ll)dp[a] + (ll)nck[b - 1][arr[a]] * dp[a + b]) % mod;
        }
    }

    int ans = 0;
    for(int a = 0; a < N; a++){
        ans = ((ll)ans + dp[a]) % mod;
    }
    cout << ans << "\n";
}
