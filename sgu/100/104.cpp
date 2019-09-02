#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int back[MAXN][MAXN];
ll val[MAXN][MAXN];
ll dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int F, V;
    cin >> F >> V;
    for (int a = 1; a <= F; a++) {
        for (int b = 1; b <= V; b++) {
            cin >> val[a][b];
        }
    }

    memset(dp, 0xaf, sizeof dp);
    dp[0][0] = 0;
    for (int a = 1; a <= F; a++) {
        for (int b = a; b <= V; b++) {
            int idx = max_element(dp[a - 1], dp[a - 1] + b) - dp[a - 1];
            dp[a][b] = max(dp[a][b], dp[a - 1][idx] + val[a][b]);
            back[a][b] = idx;
        }
    }

    vector<int> trace;
    int idx = max_element(dp[F], dp[F] + V + 1) - dp[F];
    cout << dp[F][idx] << endl;

    for (int a = F; a >= 1; a--) {
        trace.push_back(idx);

        idx = back[a][idx];
    }

    while (!trace.empty()) {
        cout << trace.back() << " ";
        trace.pop_back();
    }
}
