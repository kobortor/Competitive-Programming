#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll PP = 9705276;
const ll QQ = 12805858;
const ll MAXK = 405;
const ll MAXP = 205;

map<ll, pii> lookup;

int gain[MAXK][MAXK];

pii prv[MAXP][MAXP][MAXP];
int dp[MAXP][MAXP][MAXP];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

#ifndef DEBUG
    freopen("identification.in", "r", stdin);
    freopen("identification.out", "w", stdout);
#endif 

    for (int i = 0; i <= 400; i++) {
        for (int j = 0; j <= 400; j++) {
            lookup[i * PP + j * QQ] = pii(i, j);
        }
    }

    int n;
    cin >> n;

    ll maxv = 0;

    ll biggest_peak = -1;
    pll biggest;
    vector<pll> peaks;

    while (n--) {
#ifndef DEBUG
        string s;
        cin >> s;
        if (find(s.begin(), s.end(), '.') == s.end()) {
            s += ".00000"; // no end
        } else {
            while (s.end() - find(s.begin(), s.end(), '.') < 5) {
                s += '0';
            }
        }
        s.erase(find(s.begin(), s.end(), '.'));
        ll y = stoll(s);

        if (!lookup.count(y)) {
            continue;
        }

        pll p = lookup[y];
#else
        pll p;
        cin >> p.first >> p.second;
        ll y = p.first * PP + p.second * QQ;
#endif

        peaks.push_back(p);

        if (y > biggest_peak) {
            biggest_peak = y;
            biggest = p;
        }
    }

    ll nP = biggest.first;
    ll nQ = biggest.second;

    for (pll p : peaks) {
        if (p.first > nP || p.second > nQ) continue;

        if ((p.first + p.second) * 2 <= nP + nQ) {
            gain[p.first][p.second]++;
        } else {
            gain[nP - p.first][nQ - p.second]++;
        }
    }

    memset(dp, 0xaf, sizeof dp);
    dp[0][0][0] = 0;

    for (int tot = 1; tot * 2 <= nP + nQ + 1; tot++) {
        for (int p1 = 0; p1 <= tot; p1++) {
            for (int p2 = 0; p2 <= tot; p2++) {
                int is_final = (tot * 2 == nP + nQ + 1);

                int q1 = tot - p1;
                int q2 = tot - p2;

                if (p1 + p2 - is_final > nP || q1 + q2 - is_final > nQ) continue;

                ll reward = 0;

                reward += gain[p1][q1];
                reward += gain[p2][q2];

                if (p1 == p2 && q1 == q2) {
                    reward /= 2;
                }

                for (int take_p1 : {0, 1}) {
                    for (int take_p2 : {0, 1}) {
                        if (is_final && take_p1 != take_p2) continue;

                        int take_q1 = 1 - take_p1;
                        int take_q2 = 1 - take_p2;

                        if (p1 >= take_p1 && p2 >= take_p2 && q1 >= take_q1 && q2 >= take_q2) {
                            int newv = dp[tot - 1][p1 - take_p1][p2 - take_p2] + reward;
                            if (newv > dp[tot][p1][p2]) {
                                dp[tot][p1][p2] = newv;
                                prv[tot][p1][p2] = pii(take_p1, take_p2);
                            }
                        }
                    }
                }
            }
        }
    }

    int halflen = (nP + nQ + 1) / 2;

    int best_p1 = 0;
    int best_p2 = nP - 0;
    for (int middle_p : {0, 1}) {
        for (int p1 = 0; p1 <= nP; p1++) {
            int p2 = nP + (middle_p) - p1;
            if (dp[halflen][p1][p2] > dp[halflen][best_p1][best_p2]) {
                best_p1 = p1;
                best_p2 = p2;
            }
        }
    }

    int len = halflen;
    int p1 = best_p1;
    int p2 = best_p2;

    deque<char> dq;

    while (len > 0) {
        auto [take_p1, take_p2] = prv[len][p1][p2];
        p1 -= take_p1;
        p2 -= take_p2;
        len--;
        if (take_p1) {
            dq.push_front('P');
        } else {
            dq.push_front('Q');
        }

        if (take_p2) {
            dq.push_back('P');
        } else {
            dq.push_back('Q');
        }
    }

    if ((nP + nQ) % 2 == 1) {
        dq.erase(dq.begin() + dq.size() / 2);
    }

    cout << string(dq.begin(), dq.end()) << endl;
}
