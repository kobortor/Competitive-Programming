#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;

    ll dx = x1 - x2;
    ll dy = y1 - y2;

    if (dx * dx + dy * dy >= R * R) {
        cout << x1 << " " << y1 << " " << R;
    } else {
        double r = sqrt(dx * dx + dy * dy);
        double vx, vy;

        if (r == 0) {
            vx = 1;
            vy = 0;
        } else {
            vx = dx / r;
            vy = dy / r;
        }

        double rr = (R + r) / 2.0;
        cout << fixed << setprecision(15) << x2 + rr * vx << " " << y2 + rr * vy << " " << rr;
    }
}
