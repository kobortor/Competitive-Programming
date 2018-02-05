#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 33;

int N, M;
int minR[MAXN], maxB[MAXN];
ll dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M;
    for(int a = 0; a < N; a++){
        minR[a] = M + 1;
        maxB[a] = 0;
        string str;
        cin >> str;
        for(int b = 0; b < (int)str.size(); b++) {
            if(str[b] == 'R'){
                minR[a] = min(minR[a], b + 1);
            }
            if(str[b] == 'B'){
                maxB[a] = max(maxB[a], b + 1);
            }
        }
        if(minR[a] <= maxB[a]){
            cout << 0;
            return 0;
        }
    }

    dp[N][0] = 1;
    for(int a = N - 1; a >= 0; a--){
        ll sum = 0;
        for(int b = 0; b < minR[a]; b++){
            sum += dp[a + 1][b];
            if(maxB[a] <= b){
                dp[a][b] += sum;
            }
        }
    }
    ll ans = 0;
    for(int a = 0; a <= M; a++){
        ans += dp[0][a];
    }

    cout << ans;
}
