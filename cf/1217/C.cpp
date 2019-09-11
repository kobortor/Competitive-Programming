#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
int prefix[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        s = "!" + s; for (int a = 1; a <= n; a++) {
            prefix[a] = prefix[a - 1] + (s[a] == '1');
        }

        int ans = 0;
        for (int a = 1; a <= n; a++) {
            int prvv = 0;

            int val = 0;
            for (int b = 1; b <= min(30, a); b++) {
                if (s[a - b + 1] == '1') val += 1 << (b - 1);

                if (a >= val && prefix[a - b] - prefix[a - val] == 0 && val != prvv) {
                    prvv = val;
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
}
