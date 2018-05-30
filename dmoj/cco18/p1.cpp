#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N;
string S, T;
int A[MAXN], B[MAXN];

int dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    cin >> S;
    for(int a = 1; a <= N; a++) cin >> A[a];

    cin >> T;
    for(int a = 1; a <= N; a++) cin >> B[a];

    S = "$" + S;
    T = "$" + T;

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            dp[a][b] = max(dp[a-1][b], dp[a][b-1]);

            if(S[a] == 'W' && T[b] == 'L' && A[a] > B[b]){
                dp[a][b] = max(dp[a][b], dp[a-1][b-1] + A[a] + B[b]);
            }

            if(S[a] == 'L' && T[b] == 'W' && A[a] < B[b]){
                dp[a][b] = max(dp[a][b], dp[a-1][b-1] + A[a] + B[b]);
            }
        }
    }
    
    cout << dp[N][N];
}
