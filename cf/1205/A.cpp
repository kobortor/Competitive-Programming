#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

ll ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int a = 1; a <= n; a++) {
        if (a % 2 == 1) {
            ans[a] = 2 * a - 1;
            ans[a + n] = 2 * a;
        } else {
            ans[a] = 2 * a;
            ans[a + n] = 2 * a - 1;
        }
    }

    int sum = 0;
    for (int a = 1; a <= n; a++) sum += ans[a];

    int lo = sum, hi = sum;
    for (int a = n + 1; a <= 2 * n; a++) {
        sum += ans[a] - ans[a - n];
        lo = min(lo, sum);
        hi = max(hi, sum);
    }
    for (int a = 1; a <= n; a++) {
        sum += ans[a] - ans[a + n];
        lo = min(lo, sum);
        hi = max(hi, sum);
    }

    if (hi - lo <= 1) {
        cout << "YES\n";
        for (int a = 1; a <= 2 * n; a++) {
            cout << ans[a] << " ";
        }
    } else {
        cout << "NO";
    }
}
