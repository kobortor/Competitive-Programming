#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200;
ll dp[MAXN][MAXN][2];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    string input;

    while (true) {
        int n;
        set<string> ignore_words;

        getline(cin, input);
        n = stoi(input);

        if (n == 0) break;

        while (n--) {
            getline(cin, input);
            ignore_words.insert(input);
        }

        while (true) {
            getline(cin, input);
            if (input == "LAST CASE") {
                // die
                break;
            }

            stringstream ss(input);
            string acro;
            ss >> acro;

            vector<ll> prv(acro.size() + 1);
            prv[0] = 1;
            while (ss >> input) {
                if (ignore_words.count(input)) continue;
                memset(dp, 0, sizeof dp);
                for (int i = 0; i <= (int)acro.size(); i++) {
                    dp[i][0][false] = prv[i];
                }

                for (int j = 1; j <= (int)input.size(); j++) {
                    for (int i = 1; i <= (int)acro.size(); i++) {
                        if (toupper(input[j - 1]) == acro[i - 1]) {
                            // use letter
                            dp[i][j][true] += dp[i - 1][j - 1][true];
                            dp[i][j][true] += dp[i - 1][j - 1][false];
                        }

                        // don't use
                        dp[i][j][false] += dp[i][j - 1][false];
                        dp[i][j][true] += dp[i][j - 1][true];
                    }
                    dp[0][j][false] += dp[0][j - 1][false];
                }

                for (int i = 0; i <= (int)acro.size(); i++) {
                    prv[i] = dp[i][input.size()][true];
                }
            }

            if (prv.back() == 0) {
                cout << acro << " is not a valid abbreviation\n";
            } else {
                cout << acro << " can be formed in " << prv.back() << " ways\n";
            }
        }
    }
}