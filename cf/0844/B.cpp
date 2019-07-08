#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    for (vector<int> &vv : v) {
        for (int &i : vv) {
            cin >> i;
        }
    }

    ll ans = 0;
    for (int a = 0; a < n; a++) {
        int c0 = 0, c1 = 0;
        for (int b = 0; b < m; b++) {
            c0 += v[a][b] == 0;
            c1 += v[a][b] == 1;
        }

        ans += (1ll << c0) - 1;
        ans += (1ll << c1) - 1;
    }

    for (int b = 0; b < m; b++) {
        int c0 = 0, c1 = 0;
        for (int a = 0; a < n; a++) {
            c0 += v[a][b] == 0;
            c1 += v[a][b] == 1;
        }

        ans += (1ll << c0) - 1;
        ans += (1ll << c1) - 1;
    }

    cout << ans - n * m;
}
