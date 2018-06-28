#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string N;
int dp[1 << 10];

int val(int state){
    int ans = 0;
    int p10 = 1;
    bool lead0 = false;
    for(int a = 0; a < (int)N.size(); a++){
        if(!(state & (1 << a))){
            ans += p10 * (N[a] - '0');
            p10 *= 10;
            lead0 = (N[a] == '0');
        }
    }
    return lead0 ? 2 : ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    reverse(allof(N));

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int a = 1; a < int(1 << N.size()); a++){
        for(int b = 0; b < (int)N.size(); b++){
            if(a & (1 << b)){
                dp[a] = min(dp[a], dp[a & ~(1 << b)] + 1);
            }
        }
    }

    int ans = 1e9;
    for(int a = 0; a < int(1 << N.size()) - 1; a++){
        int tmp = val(a);
        int sq = sqrt(tmp);
        if(sq * sq == tmp){
            ans = min(ans, dp[a]);
        }
    }
    if(ans > 100){
        cout << -1;
    } else {
        cout << ans;
    }
}
