#include<bits/stdc++.h>

// Created by kobortor On 18:39:13 on 10-03-2024

using namespace std;

#define allof(x) (x).begin(), (x).end()

#define ll long long
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

const ll mod = 998244353;

ll dp[MAXN];
ll prefix[MAXN];
ll p[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<ll, ll> posn;
        posn[-1] = 0;
        vector<pll> stk;
        stk.push_back({-1, 0});
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            posn[p[i]] = i;

            while (stk.back().first > p[i]) {
                stk.pop_back();
            }

            dp[i] = 0;
            dp[i] += prefix[i - 1] - prefix[posn[stk.back().first]];
            dp[i] += stk.back().second;

            if (stk.back().first == -1) {
                dp[i]++;
            }

            dp[i] %= mod;
            if (dp[i] < 0) {
                dp[i] += mod;
            }

            stk.push_back({p[i], stk.back().second + dp[i]});

            prefix[i] = prefix[i - 1] + dp[i];
        }

        ll ans = 0;
        for (int i = n, smallest = 2e9; i >= 1; i--) {
            if (p[i] < smallest) {
                ans += dp[i];
                smallest = p[i];
            }
        }

        ans %= mod;
        cout << ans << endl;
    }
}
