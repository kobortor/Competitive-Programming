#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

bool dp[MAXN][3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;

    for(int a = 2; a <= (int)str.size(); a++){
        dp[a][0] |= dp[a - 1][0]; //AB
        dp[a][1] |= dp[a - 1][1]; //BA
        dp[a][2] |= dp[a - 1][2]; //both

        if(str[a - 2] == 'A' && str[a - 1] == 'B'){
            dp[a][0] = true;
            dp[a][2] |= dp[a - 2][1];
        }
        if(str[a - 2] == 'B' && str[a - 1] == 'A'){
            dp[a][1] = true;
            dp[a][2] |= dp[a - 2][0];
        }
    }
    cout << (dp[str.size()][2] ? "YES" : "NO");
}
