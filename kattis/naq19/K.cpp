#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int nxt[MAXN][26];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    for (int i = 0; i < 26; i++) {
        nxt[s.size()][i] = s.size();
    }

    for (int a = (int)s.size() - 1; a >= 0; a--) {
        copy(nxt[a + 1], nxt[a + 1] + 26, nxt[a]);
        nxt[a][s[a] - 'a'] = a;
    }

    int ans = 0;
    for (int a = 0; a < (int)s.size(); a++) {
        int nxta = nxt[a + 1][s[a] - 'a'];
        for (char b = 'a'; b <= 'z'; b++) {
            if (b == s[a]) {
                continue;
            }

            int nxtb = nxt[a + 1][b - 'a'];
            if (nxtb < nxta) {
                ans++;
            }
        }
    }

    cout << ans;
}
