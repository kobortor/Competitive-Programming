#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int grid[3][MAXN];
bool vis[3][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        string s;

        cin >> s;
        for (int a = 1; a <= n; a++) {
            grid[1][a] = s[a - 1] - '0';
        }

        cin >> s;
        for (int a = 1; a <= n; a++) {
            grid[2][a] = s[a - 1] - '0';
        }

        for (int a = 0; a <= n; a++) {
            vis[1][a] = false;
            vis[2][a] = false;
        }

        pii pos{1, 0};
        pii dir{0, 1};

        while (pos.second <= n) {
            int r = pos.first;
            int c = pos.second;

            if (r < 1 || r > 2) break;
            if (vis[r][c]) break;

            vis[r][c] = true;

            if (grid[r][c] <= 2) {
                // keep going straight
            } else {
                if (dir.first == 0) {
                    // going right,
                    // now turn up or down
                    if (r == 1) {
                        dir = pii(1, 0);
                    } else {
                        dir = pii(-1, 0);
                    }
                } else {
                    dir = pii(0, 1);
                }
            }
            pos = { r + dir.first, c + dir.second };
        }

        if (pos != pii(2, n + 1)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
