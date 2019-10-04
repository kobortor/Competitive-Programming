#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
const ll mod = 1e9 + 7;

int r[MAXN];
int c[MAXN];

bool black[MAXN][MAXN];
bool white[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int h, w;
    cin >> h >> w;

    for (int a = 1; a <= h; a++) {
        cin >> r[a];
        for (int b = 1; b <= r[a]; b++) {
            black[a][b] = true;
        }
        white[a][r[a] + 1] = true;
    }
    for (int a = 1; a <= w; a++) {
        cin >> c[a];
        for (int b = 1; b <= c[a]; b++) {
            black[b][a] = true;
        }
        white[c[a] + 1][a] = true;
    }

    ll ans = 1;
    for (int a = 1; a <= h; a++) {
        for (int b = 1; b <= w; b++) {
            if (black[a][b] && white[a][b]) {
                cout << 0;
                return 0;
            } else if (!black[a][b] && !white[a][b]) {
                ans = ans * 2 % mod;
            }
        }
    }

    cout << ans;
}
