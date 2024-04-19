#include <bits/stdc++.h>

// Created by kobortor On 21:20:03 on 16-04-2024

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> get_factors(int n) {
    vector<int> v;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i * i != n) {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}

const int MAXN = 105;
const int MAXF = 255;
int A[MAXN][MAXN];
bool dist[MAXN][MAXN][MAXF];
int factor_lookup[(int)1e6+6];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> A[i][j];
            }
        }

        memset(dist, 0, sizeof dist);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                A[i][j] = __gcd(A[i][j], A[n][m]);
            }
        }

        vector<int> factors = get_factors(A[n][m]);
        for (int i = 0; i < factors.size(); i++) {
            factor_lookup[factors[i]] = i;
        }

        dist[1][1][factor_lookup[A[1][1]]] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i != 1) {
                    for (int k = 0; k < factors.size(); k++) {
                        if (dist[i - 1][j][k]) {
                            dist[i][j]
                                [factor_lookup[__gcd(A[i][j], factors[k])]] = 1;
                        }
                    }
                }
                if (j != 1) {
                    for (int k = 0; k < factors.size(); k++) {
                        if (dist[i][j - 1][k]) {
                            dist[i][j]
                                [factor_lookup[__gcd(A[i][j], factors[k])]] = 1;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int k = 0; k < factors.size(); k++) {
            if (dist[n][m][k]) {
                ans = max(ans, factors[k]);
            }
        }
        cout << ans << "\n";
    }
}
