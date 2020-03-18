#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int ans = 1;
        for (int i = 0; i < (int)s.size(); /* nothing */) {
            if (s[i] == 'R') {
                i++;
                continue;
            }
            int len = 1;
            while (i + len < (int)s.size() && s[i + len] == 'L') {
                len++;
            }

            ans = max(ans, len + 1);
            i += len;
        }

        cout << ans << "\n";
    }
}
