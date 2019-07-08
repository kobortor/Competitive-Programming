#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXX = 257;

struct mat {
    double data[MAXX][MAXX];
    mat () {
        for (int a = 0; a < MAXX; a++) {
            for (int b = 0; b < MAXX; b++) {
                data[a][b] = 0;
            }
        }
    }

    mat operator* (const mat &m) const {
        mat ans;
        for (int a = 0; a < MAXX; a++) {
            for (int b = 0; b < MAXX; b++) {
                for (int c = 0; c < MAXX; c++) {
                    ans.data[a][c] += data[a][b] * m.data[b][c];
                }
            }
        }

        return ans;
    }
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    int m = 1;
    while (m <= x) {
        m = m * 2;
    }

    mat M, ans;
    for (int a = 0; a < m; a++) {
        ans.data[a][a] = 1;
    }

    for (int a = 0; a <= x; a++) {
        double d;
        cin >> d;
        for (int b = 0; b <= m; b++) {
            M.data[b][b ^ a] += d;
        }
    }

    while (n) {
        if (n & 1) {
            ans = ans * M;
        }

        M = M * M;
        n /= 2;
    }

    cout << fixed << setprecision(10) << 1.0 - ans.data[0][0];
}
