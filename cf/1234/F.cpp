#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int n;
string s;
int arr[MAXN];

int ds[1<<10][1<<10];

int bitcnt[1<<10];

vector<int> abv[1<<10];
vector<int> dis[1<<10];

bitset<1 << 20> seen;
int qcnt[1 << 20];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int a = 0; a < (1<<10); a++) {
        for (int b = 0; b < (1<<10); b++) {
            if ((a & b) == a) abv[a].push_back(b);
            if ((a & b) == 0) dis[a].push_back(b);
        }
    }

    for (int a = 0; a < (1<<10); a++) {
        int b = a;
        while (b) {
            bitcnt[a]++;
            b -= b & -b;
        }
    }

    cin >> s;
    n = s.size();

    for (int a = 1; a <= n; a++) {
        arr[a] = 1 << (s[a - 1] - 'a');
    }


    for (int a = 0; a <= n; a++) {
        int val = 0;
        for (int b = a + 1; b <= n; b++) {
            if (val & arr[b]) {
                break;
            }

            val |= arr[b];
            qcnt[val]++;
        }
    }

    int ans = 0;
    for (int a = 0; a <= n; a++) {
        int val = 0;
        for (int b = a; b >= 1; b--) {
            if (val & arr[b]) {
                break;
            }

            val |= arr[b];

            if (seen[val]) continue;
            seen[val] = true;

            int fr = val >> 10;
            int bk = val & 0b1111111111;

            int bits = bitcnt[fr] + bitcnt[bk];

            for (int c : abv[fr]) {
                ds[c][bk] = max(ds[c][bk], bits);
            }
        }

        val = 0;
        for (int b = a + 1; b <= n; b++) {
            if (val & arr[b]) {
                break;
            }

            val |= arr[b];

            qcnt[val]--;

            if (qcnt[val] == 0) {
                int fr = val >> 10;
                int bk = val & 0b1111111111;

                int bits = bitcnt[fr] + bitcnt[bk];

                int inv_fr = (~fr) & 0b1111111111;
                for (int c : dis[bk]) {
                    ans = max(ans, ds[inv_fr][c] + bits);
                }
            }
        }
    }

    cout << ans;
}
