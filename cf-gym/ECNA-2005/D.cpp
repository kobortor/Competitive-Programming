#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MN = 1005;

int g[MN][MN], n, m, k, r, c;
pii dirk[8] = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
pii dirq[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int in(int r, int c) {
    return 1 <= r && r <= n && 1 <= c && c <= m;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int G = 0;
    while (++G) {
        cin >> n >> m;
        if (!n && !m) break;
        memset(g, 0, sizeof(g));
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> r >> c;
            g[r][c] = 1; //q
        }
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> r >> c;
            g[r][c] = 2; //k
        }
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> r >> c;
            g[r][c] = 3; //p
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (g[i][j] == 1) {
                    for (pii p : dirq) {
                        int cr = i, cc = j;
                        while (1) {
                            cr += p.first;
                            cc += p.second;
                            if (!in(cr, cc) || g[cr][cc] == 1 || g[cr][cc] == 2 || g[cr][cc] == 3) break;
                            g[cr][cc] = 4;
                        }
                    }
                } else if (g[i][j] == 2) {
                    for (pii p : dirk) {
                        int cr = i + p.first;
                        int cc = j + p.second;
                        if (!in(cr, cc) || g[cr][cc] == 1 || g[cr][cc] == 2 || g[cr][cc] == 3) continue;
                        g[cr][cc] = 4;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                //printf("%d", g[i][j]);
                if (!g[i][j]) ans++;
            }
            //printf("\n");
        }    return 0;
}
        printf("Board %d has %d safe squares.\n", G, ans);
    }
}