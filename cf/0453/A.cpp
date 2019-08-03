#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int m, n;
    cin >> m >> n;

    double ans = 0;
    for (int a = 1; a <= m; a++) {
        ans += a * ((1.0 - pow((double)(a - 1) / m, n)) - (1.0 - pow((double) a / m, n)));
    }
    cout << fixed << setprecision(10) << ans;
}
