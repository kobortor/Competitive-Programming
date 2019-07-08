#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 9;

struct mat {
    ll data[2][2];
    mat () {
        memset(data, 0, sizeof data);
    }

    mat operator* (const mat &m) const {
        mat ans;
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 2; c++) {
                    ans.data[a][b] += data[a][c] * m.data[c][b];
                }
                ans.data[a][b] %= mod;
            }
        }

        return ans;
    }
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m, k;
    cin >> n >> m >> k;
    
    ll gaps = n - m;

    if (gaps * k + (k - 1) >= n) {
        cout << m;
    } else {
        ll nblocks = (m - (k - 1) * gaps) / k;
        ll extra = m - nblocks * k;

        mat block;
        block.data[0][0] = 2;
        block.data[1][0] = 2 * k;
        block.data[1][1] = 1;

        mat ans;
        ans.data[0][0] = 1;
        ans.data[1][1] = 1;

        while (nblocks) {
            if (nblocks & 1) {
                ans = ans * block;
            }

            block = block * block;
            nblocks /= 2;
        }
        cout << (ans.data[1][0] + extra) % mod;
    }
}
