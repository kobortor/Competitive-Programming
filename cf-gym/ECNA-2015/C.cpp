#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<short, short> pii;
typedef pair<ll, ll> pll;

const int MAXN = 12;

int n, m, t;
char op;

pii points[MAXN];
bool freq_row[MAXN][MAXN];
bool freq_col[MAXN][MAXN];
ll pow9[MAXN];

int ans = 0;

void recur_plus(int i, int cur) {
    if (i + 1 == m) {
        int x = t - cur;
        if (1 <= x && x <= n) {
            ans += !(freq_row[points[i].first][x] || freq_col[points[i].second][x]);
        }
        return;
    }

    if (cur > t) return;
    if (t - cur > 9 * (m - i)) {
        return;
    }
    if (cur + (m - i) > t) {
        return;
    }

    for (int x = 1; x <= n; x++) {
        if (freq_row[points[i].first][x] || freq_col[points[i].second][x]) {
            continue;
        }

        freq_row[points[i].first][x] = true;
        freq_col[points[i].second][x] = true;

        recur_plus(i + 1, cur + x);

        freq_row[points[i].first][x] = false;
        freq_col[points[i].second][x] = false;
    }
}

vector<int> factors;


void recur_times(int i, int cur) {
    if (cur > t || t % cur != 0) return;
    if (i + 1 == m) {
        int x = t / cur;
        if (1 <= x && x <= n) {
            ans += !(freq_row[points[i].first][x] || freq_col[points[i].second][x]);
        }
        return;
    }

    if (cur * pow9[m - i] < t) {
        return;
    }

    for (int x : factors) {
        if (freq_row[points[i].first][x] || freq_col[points[i].second][x]) {
            continue;
        }

        freq_row[points[i].first][x] = true;
        freq_col[points[i].second][x] = true;

        recur_times(i + 1, cur * x);

        freq_row[points[i].first][x] = false;
        freq_col[points[i].second][x] = false;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pow9[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow9[i] = pow9[i - 1] * 9;
    }

    cin >> n >> m >> t >> op;

    if (op == '-') {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (i - j == t || j - i == t) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    } else if (op == '/') {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (i == t * j || j == t * i) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    } else {
        for (int i = 0, x, y; i < m; i++) {
            cin >> x >> y;
            points[i].first = x;
            points[i].second = y;
        }
        sort(points, points + m);
        if (op == '+') {
            recur_plus(0, 0);
            cout << ans << endl;
        } else {
            for (int x = 1; x <= n; x++) {
                if (t % x == 0) {
                    factors.push_back(x);
                }
            }
            recur_times(0, 1);
            cout << ans << endl;
        }
    }
}
