#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        vector<int> v(s.size());
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'a') v[i] = 0;
            else if (s[i] == 'n') v[i] = 1;
            else if (s[i] == 'i') v[i] = 2;
            else v[i] = 3;
        }

        const int MOD = 4*4*4;
        vector<ll> dp(4*4*4, 1e9);
        vector<ll> dp2(4*4*4);
        dp[3*4*4 + 3*4 + 3] = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            fill(allof(dp2), 1e9);
            for (int j = 0; j < 4*4*4; j++) {
                for (int k = 0; k < 4; k++) {
                    int cost = (k != v[i]);
                    int nxt = (j * 4 + k) % MOD;

                    if (j*4 + k == 0*4*4*4 + 1*4*4 + 2*4 + 0) { // ania
                        continue;
                    } else {
                        dp2[nxt] = min(dp2[nxt], dp[j] + cost);
                    }
                }
            }
            swap(dp, dp2);
        }

        cout << *min_element(allof(dp)) << "\n";
    }
}
