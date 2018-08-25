#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXT = 1e5 + 5;

int N, C, S;
int dp[MAXT][1 << 5];
int A[5], B[5];

int cost[1 << 5];
int cook[1 << 5];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> C >> S;

    for(int a = 0; a < N; a++){
        cin >> A[a] >> B[a];
        for(int b = 0; b < (1 << N); b++){
            if(b & (1 << a)){
                cost[b] += A[a];
                cook[b] += B[a];
            }
        }
    }

    memset(dp, 0xaf, sizeof dp);
    dp[0][0] = 0;

    for(int a = 1; a < MAXT; a++){
        for(int b = 0; b < (1 << N); b++){
            for(int c = 0; c < (1 << N); c++){
                if((b & c) != c){
                    continue;
                }
                if(dp[a - 1][c] + cook[c] - cost[b ^ c] + S >= 0){
                    dp[a][b] = max(dp[a][b], dp[a - 1][c] + cook[c] - cost[b ^ c] + S);
                }
            }
            if(dp[a][b] >= C){
                cout << a;
                return 0;
            }
        }
    }
}
