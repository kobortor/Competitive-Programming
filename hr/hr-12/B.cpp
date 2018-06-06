#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3005;
int N, K;
ll dp[MAXN][MAXN];

int pos[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        cin >> pos[a];
    }
    sort(pos + 1, pos + N + 1);

    for(int a = 0; a < MAXN; a++){
        fill(dp[a], dp[a] + MAXN, 1e18);
    }
    
    dp[0][0] = 0;
    for(int a = 0; a < N; a++){
        ll gap = pos[a + 1] - pos[a];
        for(int b = 0; b <= a; b++){
            ll lftA = b;
            ll lftB = a - b;
            ll rhtA = K - lftA;
            ll rhtB = N - K - lftB;

            ll cost = (lftB * rhtA + lftA * rhtB) * gap;
            dp[a + 1][b] = min(dp[a + 1][b], dp[a][b] + cost);
            dp[a + 1][b + 1] = min(dp[a + 1][b + 1], dp[a][b] + cost);
        }
    }

    cout << dp[N][K];
}
