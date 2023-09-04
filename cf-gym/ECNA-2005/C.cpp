#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int step(int n, int m, int mask) {
    
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b = a;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ci = i * m + j;
            if (mask & (1 << ci)) a[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ngb = 0;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = (i + dr + n) % n;
                    int nc = (j + dc + m) % m;
                    ngb += a[nr][nc];
                }  
            }
            if (a[i][j]) {
                if (ngb == 2 || ngb == 3) b[i][j] = 1;
            }
            else {
                if (ngb == 3) b[i][j] = 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ci = i * m + j;
            if (b[i][j]) res ^= (1 << ci);
        }
    }
    return res;

}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int tt = 1;

    while (1) {
        int n, m; cin >> n >> m;

        if (n == 0 && m == 0) break;

        int k; cin >> k;
        int fv = 0;
        while (k--) {
            int r, c; cin >> r >> c;
            fv ^= (1 << (r * m + c));
        }
    

        int ans = 0;
        for (int i = 0; i < (1 << (n * m)); i++) {
            ans += (step(n, m, i) == fv);
        }

        cout << "Case " << (tt++) << ": ";
        if (ans == 0) cout << "Garden of Eden.\n";
        else cout << ans << " possible ancestors.\n";

    }

}
