#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 605;

int W, H;
int N;
pii slabs[MAXN];
int dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> W >> H;
    
    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> slabs[a].first >> slabs[a].second;
    }

    memset(dp, 0x3f, sizeof dp);

    for(int a = 1; a <= W; a++){
        for(int b = 1; b <= H; b++){
            for(int c = 1; c <= N; c++){
                if(slabs[c].first <= a && slabs[c].second <= b){
                    dp[a][b] = min(dp[a][b], a * b - slabs[c].first * slabs[c].second);
                }
            }

            for(int c = 1; c <= a - 1; c++){
                dp[a][b] = min(dp[a][b], dp[c][b] + dp[a - c][b]);
            }

            for(int c = 1; c <= b - 1; c++){
                dp[a][b] = min(dp[a][b], dp[a][c] + dp[a][b - c]);
            }
        }
    }

    cout << dp[W][H];
}
