#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
const int MAXL = 55;

string str;
string s, t;

int jmps[MAXL][26];
int jmpt[MAXL][26];

int dp[MAXN][MAXL][MAXL];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> str >> s >> t;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        for (int a = 0; a <= (int)s.size(); a++) {
            jmps[a][(int)ch] = 0;
            for (int b = a + 1; b >= 1; b--) {
                if (b >= (int)s.size()) continue;
                if (s.substr(a - b + 1, b - 1) + ch == s.substr(0, b)) {
                    jmps[a][(int)ch] = b;
                    break;
                }
            }
        }
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        for (int a = 0; a <= (int)t.size(); a++) {
            jmpt[a][(int)ch] = 0;
            for (int b = a + 1; b >= 1; b--) {
                if (b >= (int)t.size()) continue;
                if (t.substr(a - b + 1, b - 1) + ch == t.substr(0, b)) {
                    jmpt[a][(int)ch] = b;
                    break;
                }
            }
        }
    }

    memset(dp, 0xaf, sizeof dp);
    dp[0][0][0] = 0;
    for (int a = 0; a < (int)str.size(); a++) {
        for (int ss = 0; ss < (int)s.size(); ss++) {
            for (int tt = 0; tt < (int)t.size(); tt++) {
                if (dp[a][ss][tt] < -100000) {
                    continue;
                }
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (str[a] != '*' && str[a] != ch) continue;

                    int add = 0;
                    add += ss + 1 == (int)s.size() && s[ss] == ch;
                    add -= tt + 1 == (int)t.size() && t[tt] == ch;

                    int ns = jmps[ss][(int)ch];
                    int nt = jmpt[tt][(int)ch];

                    //cout << a << " " << ss << " " << tt << " set " << dp[a][ss][tt] + add << " to " << a + 1 << " " << ns << " " << nt << endl;
                    dp[a + 1][ns][nt] = max(dp[a + 1][ns][nt], dp[a][ss][tt] + add);
                }
            }
        }
    }

    int ans = -1000000;
    for (int ss = 0; ss < (int)s.size(); ss++) {
        for (int tt = 0; tt < (int)t.size(); tt++) {
            ans = max(ans, dp[str.size()][ss][tt]);
        }
    }
    cout << ans;
}
