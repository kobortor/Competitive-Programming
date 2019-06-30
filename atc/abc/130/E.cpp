#include<iostream>
#include<utility>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
const int MAXN = 2e3 + 3;

int N, M;
int S[MAXN], T[MAXN];
ll dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    dp[0][0] = 1;
    for (int a = 1; a <= N; a++) {
        cin >> S[a];
    }

    for (int b = 1; b <= M; b++) {
        cin >> T[b];
    }

    for (int a = 0; a <= N; a++) {
        for (int b = 0; b <= M; b++) {
            if (b) dp[a][b] += dp[a][b - 1];
            if (a && b && S[a] == T[b]) {
                dp[a][b] += dp[a - 1][b - 1];
            }

            dp[a][b] %= mod;
        }

        for (int b = 0; b <= M; b++) {
            if (a) dp[a][b] += dp[a - 1][b];

            dp[a][b] %= mod;
        }
    }

    cout << dp[N][M] % mod;
}
