#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

string str;

bool dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> str;
    int K = log2(str.size());
    int N = str.size();

    for(int a = 0; a < (1 << K); a++){
        dp[0][a] = true;
    }

    for(int a = 1; a <= N - (1 << K) + 1; a++){
        for(int b = 0; b < (1 << K); b++){
            dp[a][b] = false;
        }
        char minc = 'z';
        for(int b = 0; b < (1 << K); b++){
            if(dp[a - 1][b]){
                minc = min(minc, str[a + b - 1]);
            }
        }

        for(int b = 0; b < (1 << K); b++){
            if(dp[a-1][b] && str[a+b-1] == minc){
                dp[a][b] = true;
            }

            for(int c = 0; c < K; c++){
                if((b & (1<<c)) && dp[a][b - (1<<c)]){
                    dp[a][b] = true;
                }
            }
        }
        cout << minc;
    }
}
