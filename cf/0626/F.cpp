#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 205;
const int MAXK = 1005;
const ll mod = 1e9 + 7;

int N, K;

int arr[MAXN];

int dp[MAXN][MAXN][MAXK];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }
    sort(arr + 1, arr + N + 1);

    dp[0][0][0] = 1;
    for(int a = 1; a <= N; a++){
        int diff = arr[a] - arr[a-1];

        for(int b = 0; b <= N; b++){
            for(int c = 0; c <= K; c++){
                if(b != 0){
                    //add a new group
                    if(c >= (b-1)*diff) {
                        dp[a][b][c] += dp[a-1][b-1][c-(b-1)*diff];
                        dp[a][b][c] %= mod;
                    }

                    //extend off an old group and continue it
                    if(c >= b*diff) {
                        dp[a][b][c] += (ll)dp[a-1][b][c-b*diff] * b % mod;
                        dp[a][b][c] %= mod;
                    }
                }

                //have a single person group
                if(c >= b*diff) {
                    dp[a][b][c] += dp[a-1][b][c-b*diff];
                    dp[a][b][c] %= mod;
                }

                //extend off an old group and finish it
                if(c >= (b+1)*diff) {
                    dp[a][b][c] += (ll)dp[a-1][b+1][c-(b+1)*diff]*(b+1) % mod;
                    dp[a][b][c] %= mod;
                }
            }
        }
    }

    ll ans = 0;
    for(int a = 0; a <= K; a++){
        ans += dp[N][0][a];
        ans %= mod;
    }
    cout << ans;
}
