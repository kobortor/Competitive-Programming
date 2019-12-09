#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<double> p(n);
    for (double &pi : p) cin >> pi;

    sort(allof(p), greater<double>());

    if (p[0] == 1.0) {
        cout << 1.0;
        return 0;
    }

    double ans = 0;
    double prod = 1;
    double sums = 0;
    for (int a = 0; a < n; a++) {
        prod *= 1 - p[a];
        sums += p[a] / (1 - p[a]);

        ans = max(ans, prod * sums);
    }

    cout << fixed << setprecision(15) << ans;
}
