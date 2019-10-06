#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        double w, g, h, r;
        cin >> w >> g >> h >> r;

        g -= r;
        h -= r;

        double ans1 = sqrt(w * w + (g - h) * (g - h));

        double x = g * w / (g + h + 1e-16);

        double ans2 = sqrt (x * x + g * g) + sqrt((w - x) * (w - x) + h * h);

        cout << fixed << setprecision(15) << ans1 << " " << ans2 << "\n";
    }
}
