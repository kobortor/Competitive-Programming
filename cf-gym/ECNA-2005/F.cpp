#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 3e6 + 5;

ll M1[MAXV];
ll M2[MAXV];

struct rectangle {
    ll x1, x2, y1, y2;
};

ll sq_count(ll n, ll m) {
    ll k = min(n, m);
    ll answer = 0;
    answer += k * n * m;
    answer -= (n + m) * M1[k];
    answer += k * (n + m);
    answer += M2[k];
    answer -= 2 * M1[k];
    answer += k;

    // cout << n << " " << m << " return " << answer << endl;
    return answer;
}

ll sq_count_r(rectangle r) {
    // cout << "Checking out " << r.x1 << " " << r.x2 << " " << r.y1 << " " << r.y2 << endl;
    return sq_count(r.x2 - r.x1, r.y2 - r.y1);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (ll k = 1; k < MAXV; k++) {
        M1[k] = M1[k - 1] + k;
        M2[k] = M2[k - 1] + k*k;
    }

    int tc = 0;
    while (true) {
        tc++;

        int n;
        cin >> n;
        if (n == 0) break;

        vector<rectangle> rs;

        ll answer = 0;
        for (int i = 0; i < n; i++) {
            rectangle r;
            cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;

            if (r.x1 > r.x2) {
                swap(r.x1, r.x2);
            }
            if (r.y1 > r.y2) {
                swap(r.y1, r.y2);
            }
            // r.x2++;
            // r.y2++;
            rs.push_back(r);
            answer += sq_count_r(r);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                rectangle r1 = rs[i];
                rectangle r2 = rs[j];

                ll dx = min(r1.x2, r2.x2) - max(r1.x1, r2.x1);
                ll dy = min(r1.y2, r2.y2) - max(r1.y1, r2.y1);

                // cout << "dx dy = " << dx << " " << dy << endl;

                if (dx == 0) {
                    ll m = dy;
                    ll h1 = r1.x2 - r1.x1;
                    ll h2 = r2.x2 - r2.x1;

                    if (m > 2) {
                        answer += sq_count(h1 + h2, m - 2);
                        answer -= sq_count(h1, m - 2);
                        answer -= sq_count(h2, m - 2);
                    }
                }

                if (dy == 0) {
                    ll m = dx;
                    ll h1 = r1.y2 - r1.y1;
                    ll h2 = r2.y2 - r2.y1;

                    if (m > 2) {
                        answer += sq_count(h1 + h2, m - 2);
                        answer -= sq_count(h1, m - 2);
                        answer -= sq_count(h2, m - 2);
                    }
                }
            }
        }

        cout << "Case " << tc << ": " << answer << endl;
    }
}