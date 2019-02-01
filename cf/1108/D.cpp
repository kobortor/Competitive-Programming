#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
string S;
int dp[MAXN][3];

int getid(char c){
    switch(c){
        case 'R': return 0;
        case 'G': return 1;
        case 'B': return 2;
    }
    return -1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);


    cin >> N >> S;

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int a = 1; a <= N; a++){
        dp[a][0] = dp[a][1] = dp[a][2] = 9999999;
        int val = getid(S[a - 1]);

        for(int b = 0; b < 3; b++){
            for(int c = 0; c < 3; c++){
                if (b != c) {
                    dp[a][b] = min(dp[a][b], dp[a - 1][c] + (b != val));
                }
            }
        }
    }

    int cur = min_element(dp[N], dp[N] + 3) - dp[N];
    cout << dp[N][cur] << "\n";
    string ans;
    for(int a = N; a >= 1; a--){
        switch(cur){
            case 0: ans += 'R'; break;
            case 1: ans += 'G'; break;
            case 2: ans += 'B'; break;
        }
        if(dp[a - 1][(cur + 1) % 3] < dp[a - 1][(cur + 2) % 3]){
            cur = (cur + 1) % 3;
        } else {
            cur = (cur + 2) % 3;
        }
    }

    reverse(allof(ans));

    cout << ans;
}
