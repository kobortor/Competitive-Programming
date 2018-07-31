#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 205;
const ll mod = 1e9 + 7;

int N;
string S;

//[cur][unbalance][matched]
ll dp[MAXN][MAXN][MAXN];
int nxt[MAXN][2];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> S;

    for(int a = 0; a < (int)S.size(); a++){
        for(int b = a; b >= 0; b--){
            bool good = S[b] == '(';
            for(int c = 0; c < b; c++){
                good &= S[c] == S[a - b + c];
            }
            if(good){
                nxt[a][0] = b + 1;
                break;
            }
        }

        for(int b = a; b >= 0; b--){
            bool good = S[b] == ')';
            for(int c = 0; c < b; c++){
                good &= S[c] == S[a - b + c];
            }
            if(good){
                nxt[a][1] = b + 1;
                break;
            }
        }
    }

    N *= 2;
    dp[0][0][0] = 1;
    for(int a = 0; a < N; a++){
        for(int b = 0; b <= a; b++){
            for(int c = 0; c < (int)S.size(); c++){
                dp[a][b][c] %= mod;
                dp[a + 1][b + 1][nxt[c][0]] += dp[a][b][c];
                if(b != 0){
                    dp[a + 1][b - 1][nxt[c][1]] += dp[a][b][c];
                }
            }

            dp[a][b][S.size()] %= mod;
            dp[a + 1][b + 1][S.size()] += dp[a][b][S.size()];
            if(b != 0){
                dp[a + 1][b - 1][S.size()] += dp[a][b][S.size()];
            }
        }
    }

    cout << dp[N][0][S.size()] % mod;
}
