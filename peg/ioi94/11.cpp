#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;
int dp[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        int prv = 0;
        for(int b = 0; b <= a; b++){
            int x;
            cin >> x;

            int tmp = dp[b];
            dp[b] = max(prv, dp[b]) + x;
            prv = tmp;
        }
    }

    cout << *max_element(dp, dp + MAXN);
}
