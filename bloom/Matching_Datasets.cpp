#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//Also works for "Matching Datasets++"

const int MAXN = 1001;
string A[MAXN], B[MAXN];

int diff(string s1, string s2){
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));

    for(int a = 0; a < (int)s1.size(); a++){
        for(int b = 0; b < (int)s2.size(); b++){
            dp[a + 1][b + 1] = min(dp[a][b + 1], dp[a + 1][b]) + 1;
            if(s1[a] == s2[b]){
                dp[a + 1][b + 1] = min(dp[a + 1][b + 1], dp[a][b]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int K;
    cin >> K;
    for(int a = 0; a < K; a++) cin >> A[a];
    for(int a = 0; a < K; a++) cin >> B[a];

    for(int a = 0; a < K; a++){
        int best = 0;
        int bestdiff = diff(A[a], B[0]);
        for(int b = 1; b < K; b++){
            int ndiff = diff(A[a], B[b]);
            if(ndiff < bestdiff){
                bestdiff = ndiff;
                best = b;
            }
        }
        cout << a << "," << best << endl;
    }
}
