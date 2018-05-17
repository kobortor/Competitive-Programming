#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N, M;
int val[26];

int dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < 26; a++){
        cin >> val[a];
    }

    string A, B;
    cin >> A >> B;

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            dp[a][b] = max(dp[a-1][b], dp[a][b-1]);
            if(A[a-1] == B[b-1]){
                dp[a][b] = max(dp[a][b], dp[a-1][b-1] + val[A[a-1] - 'a']);
            }
        }
    }
    cout << dp[N][M];
}
