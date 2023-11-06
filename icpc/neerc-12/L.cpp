#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define f first
#define s second

const int MN = 1505;

int n, m, psa[MN][MN], psa2[MN][MN], psa3[MN][MN], vis[MN][MN];
char grid[MN][MN];
pii dir[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int sum(int b, int l, int sz) {
    int t = b + sz - 1;
    int r = l + sz - 1;
    return psa[t][r] - psa[b-1][r] - psa[t][l-1] + psa[b-1][l-1];
}

int sum2(int b, int l, int sz) {
    int t = b + sz - 1;
    int r = l + sz - 1;
    return psa2[t][r] - psa2[b-1][r] - psa2[t][l-1] + psa2[b-1][l-1];
}

int sum3(int b, int l, int sz) {
    int t = b + sz - 1;
    int r = l + sz - 1;
    return psa3[t][r] - psa3[b-1][r] - psa3[t][l-1] + psa3[b-1][l-1];
}

void mark(int r, int c, int num) {
    for (pii d : dir) {
        pii nxt = {r + d.f, c + d.s};
        if (nxt.f < 1 || nxt.f > n || nxt.s < 1 || nxt.s > m) continue;
        if (num == 2) psa2[nxt.f][nxt.s]++;
        else psa3[nxt.f][nxt.s]++;
    }

}

void process(int sr, int sc, int num) {
    queue<pii> q;
    q.push({sr, sc});
    vis[sr][sc] = 1;
    while (q.size()) {
        pii cur = q.front(); q.pop();
        mark(cur.f, cur.s, num);
        for (pii d : dir) {
            pii nxt = {cur.f + d.f, cur.s + d.s};
            if (vis[nxt.f][nxt.s] || grid[nxt.f][nxt.s] != '#') continue;
            vis[nxt.f][nxt.s] = 1;
            q.push(nxt);
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("labyrinth.in", "r", stdin);
    freopen("labyrinth.out", "w", stdout);

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                psa[i][j]++;
            }
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (grid[i][1] == '#' && !vis[i][1]) {
            process(i, 1, 2);
        }
        psa2[i][1]++;
        if (grid[i][m] == '#' && !vis[i][m]) {
            process(i, m, 3);
        }
        psa3[i][m]++;
    }
    for (int i = 1; i <= m; i++) {
        if (grid[1][i] == '#' && !vis[1][i]) {
            process(1, i, 3);
        }
        psa3[1][i]++;
        if (grid[n][i] == '#' && !vis[n][i]) {
            process(n, i, 2);
        }
        psa2[n][i]++;
    }
    psa2[1][1] = psa3[1][1] = 0;
    psa2[n][m] = psa2[n][m] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //printf("%d", psa3[i][j]);
            psa2[i][j] += psa2[i - 1][j] + psa2[i][j - 1] - psa2[i - 1][j - 1];
            psa3[i][j] += psa3[i - 1][j] + psa3[i][j - 1] - psa3[i - 1][j - 1];
        }
        //printf("\n");
    }
    int best = 0x3f3f3f3f, br = 0, bc = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            int lo = 1, hi = min(n, m), mid, ans = 0x3f3f3f3f;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (i + mid - 1 > n || j + mid - 1 > m) {
                    hi = mid - 1;
                    continue;
                }
                if (i + mid - 1 == n && j + mid - 1 == m) {
                    hi = mid - 1;
                    continue;
                }

                int s = sum(i, j, mid);
                int s2 = sum2(i, j, mid);
                int s3 = sum3(i, j, mid);
                if (s) {hi = mid - 1; continue;}
                if (s2 && s3) {
                    ans = min(ans, mid);
                    hi = mid - 1;
                } else lo = mid + 1;
            }
            if (ans < best) {
                best = ans;
                br = i;
                bc = j;
            }
        }
    }
    if (!br) printf("Impossible\n");
    else printf("%d %d %d\n", best, bc, br);
}
