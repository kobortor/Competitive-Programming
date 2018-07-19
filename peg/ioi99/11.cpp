#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int F, V;
pii dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> F >> V;
    for(int a = 1; a <= F; a++){
        pii best = pii(dp[a - 1][0].first, 0);

        dp[a][0].first = -1e9;

        for(int b = 1; b <= V; b++){
            int x;
            cin >> x;

            dp[a][b] = pii(x + best.first, best.second);

            best = max(best, pii(dp[a - 1][b].first, b));
        }
    }

    int cur = max_element(dp[F], dp[F] + V + 1) - dp[F];

    cout << dp[F][cur].first << "\n";

    vector<int> soln;
    for(int a = F; a >= 1; a--){
        soln.push_back(cur);
        cur = dp[a][cur].second;
    }

    reverse(allof(soln));

    for(int i : soln){
        cout << i << " ";
    }
}
