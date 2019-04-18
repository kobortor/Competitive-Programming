#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;
const ll mod = 1e9 + 7;

ll N, K;
ll arr[MAXN];

struct matrix {
    ll data[MAXN][MAXN];
    matrix operator* (const matrix &m) const {
        matrix ans;
        for (int a = 0; a < MAXN; a++) {
            for (int b = 0; b < MAXN; b++) {
                ans.data[a][b] = 0;
                for (int c = 0; c < MAXN; c++) {
                    ans.data[a][b] += data[a][c] * m.data[c][b];
                    ans.data[a][b] %= mod;
                }
            }
        }
        return ans;
    }
};

ll qpow (ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1) {
            ans = ans * x % mod;
        }

        x = x * x % mod;
        y >>= 1;
    }

    return ans;
}
matrix mqpow (matrix x, ll y) {
    matrix ans;
    for (int a = 0; a < MAXN; a++) {
        for (int b = 0; b < MAXN; b++) {
            ans.data[a][b] = (a == b);
        }
    }

    while (y) {
        if (y & 1) {
            ans = ans * x;
        }

        x = x * x;
        y >>= 1;
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    int n0 = 0, n1 = 0;
    for (int a = 0; a < N; a++) {
        cin >> arr[a];
        if (arr[a] == 0) {
            n0++;
        } else {
            n1++;
        }
    }

    int init = 0;
    for (int a = 0; a < N; a++) {
        if (arr[a] == 0 && a < n0) {
            init++;
        }
    }

    matrix m;
    for (int a = 0; a < MAXN; a++) {
        for (int b = 0; b < MAXN; b++) {
            m.data[a][b] = 0;
        }
    }

    for (int a = max(0, n0 - n1); a <= n0; a++) {
        ll right0 = a;
        ll wrong0 = n0 - a;

        ll wrong1 = wrong0;
        ll right1 = n1 - wrong1;

        // just swap with same things
        m.data[a][a] += n0 * (n0 - 1) / 2;
        m.data[a][a] += n1 * (n1 - 1) / 2;

        // swapping different with no effect
        m.data[a][a] += right0 * wrong1;
        m.data[a][a] += wrong0 * right1;

        // others
        if (a != 0) {
            m.data[a][a - 1] += right0 * right1;
        }

        if (a != n0) {
            m.data[a][a + 1] += wrong0 * wrong1;
        }
    }

    for (int a = 0; a <= n0; a++) {
        for (int b = 0; b <= n0; b++) {
            m.data[a][b] %= mod;
        }
    }

    m = mqpow(m, K);
    ll denom = qpow(qpow(N * (N - 1) / 2, mod - 2), K);

    cout << m.data[init][n0] * denom % mod;
}
