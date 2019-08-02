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
    vector<double> angles(n);
    for (double &d : angles) {
        double x, y;
        cin >> x >> y;
        d = atan2(x, y);
    }

    sort(allof(angles));
    double pi = acos(-1);
    double ans = angles[0] + 2 * pi - angles.back();
    for (int a = 0; a + 1 < n; a++) {
        ans = max(ans, angles[a + 1] - angles[a]);
    }
    cout << fixed << setprecision(10) << (2 * pi - ans) / pi * 180;
}
