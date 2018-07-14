#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll dp[20][20];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    string str;
    cin >> str;

    string LHS = str.substr(0, N);
    string RHS = str.substr(N, N);
    reverse(allof(RHS));
    
    ll ans = 0;

    for(int mask = 0; mask < (1 << N); mask++){
        string lft;
        string extra;
        for(int a = 0; a < N; a++){
            if(mask & (1 << a)){
                lft += str[a];
            } else {
                extra += str[a];
            }
        }

        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int a = 0; a < N; a++){
            for(int b = 0; b <= (int)lft.size(); b++){
                int c = a - b;
                if(0 <= c && c <= (int)extra.size()){
                    if(b < (int)lft.size() && RHS[a] == lft[b]){
                        dp[b + 1][c] += dp[b][c];
                    }
                    if(c < (int)extra.size() && RHS[a] == extra[c]){
                        dp[b][c + 1] += dp[b][c];
                    }
                }
            }
        }
        ans += dp[lft.size()][extra.size()];
    }
    cout << ans;
}
