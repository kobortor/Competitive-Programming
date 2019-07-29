#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    double x1, y1, r1;
    cin >> x1 >> y1 >> r1;

    double x2, y2, r2;
    cin >> x2 >> y2 >> r2;

    double diff = hypot(x1 - x2, y1 - y2);

    if (r1 + r2 > diff) {
        if (diff + min(r1, r2) < max(r1, r2)) {
            cout << fixed << setprecision(10) << (max(r1, r2) - diff - min(r1, r2)) / 2;
        } else {
            cout << "0.000000000";
        }
    } else {
        cout << fixed << setprecision(10) << (diff - r1 - r2) / 2;
    }
}
