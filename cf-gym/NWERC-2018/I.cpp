#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MN = 200005;

int n, a[MN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
    bool ok = 1;
    double ans = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > i) ok = 0;
        else ans = min(ans, (double) a[i] / (double) i);
    }
    if (!ok) printf("-1\n");
    else printf("%.8f\n", ans);
}
