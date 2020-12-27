#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const int N = 1000000;
const ll MOD1 = 10000019;
const ll MOD2 = 1e9 + 7;

ll A[N + 1];

struct BIT {
    pll bits[MOD1 + 2];
    void update(int pos, pll p) {
        pos++;
        while (pos < MOD1 + 2) {
            bits[pos].first += p.first;
            bits[pos].first %= MOD2;
            bits[pos].second += p.second;
            bits[pos].second %= MOD2;
            pos += pos & -pos;
        }
    }

    pll query(int pos) {
        pos++;
        pll ans = make_pair(0ll, 0ll);
        while (pos) {
            ans.first += bits[pos].first;
            ans.first %= MOD2;
            ans.second += bits[pos].second;
            ans.second %= MOD2;
            pos -= pos & -pos;
        }
        return ans;
    }
} ds[5];

int main() {
    A[0] = 1;
    for (int i = 1; i <= N; i++) {
        A[i] = (A[i - 1] * 153) % MOD1;
    }

    ds[0].update(0, make_pair(0, 1));
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= 4; k++) {
            pll tmp = ds[k - 1].query(A[i] - 1);

            tmp.first += tmp.second * A[i];
            tmp.first %= MOD2;

            ds[k].update(A[i], tmp);
        }
    }

    cout << ds[4].query(MOD1).first % MOD2;
}
