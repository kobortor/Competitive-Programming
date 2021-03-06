#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


double xa, xb, xc;
double ya, yb, yc;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;
    cin >> n;
    while (n--) {
        double x, y;
        cin >> x >> y;

        xa++;
        ya++;

        xb -= 2 * x;
        yb -= 2 * y;

        xc += x * x;
        yc += y * y;
    }

    ll m;
    cin >> m;

    double ans = 1e100;

    vector<pair<double, double>> pts;
    while (m--) {
        double x, y;
        cin >> x >> y;
        
        ans = min(ans, (xa*x*x + xb*x + xc) + (ya*y*y + yb*y + yc));
        pts.push_back({x, y});
    }

    bool inside = true;
    double x0 = -xb / (2 * xa), y0 = -yb / (2 * ya);

    for (int a = 0; a < (int)pts.size(); a++) {
        int b = (a + 1) % pts.size();

        double x1 = pts[a].first, y1 = pts[a].second;
        double x2 = pts[b].first, y2 = pts[b].second;

        inside &= (x0 - x1) * (y2 - y1) - (y0 - y1) * (x2 - x1) >= 0;

        double x12 = x1 - x2, x20 = x2 - x0;
        double y12 = y1 - y2, y20 = y2 - y0;
        double alpha = -(x12 * x20 + y12 * y20) / (x12 * x12 + y12 * y12);

        double x = alpha * x1 + (1 - alpha) * x2;
        double y = alpha * y1 + (1 - alpha) * y2;

        if (min(x1, x2) <= x && x <= max(x1, x2) &&
            min(y1, y2) <= y && y <= max(y1, y2)) {
            ans = min(ans, (xa*x*x + xb*x + xc) + (ya*y*y + yb*y + yc));
        } 
    }

    if (inside) {
        ans = min(ans, (xa*x0*x0 + xb*x0 + xc) + (ya*y0*y0 + yb*y0 + yc));
    }

    cout << fixed << setprecision(10) << ans;
}
