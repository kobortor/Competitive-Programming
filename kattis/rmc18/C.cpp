#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (a % b) {
        a %= b;
        swap(a, b);
    }

    return b;
}

bool inbox(ll x, ll y, ll x1, ll y1, ll x2, ll y2) {
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll xb, yb;
    cin >> xb >> yb;

    ll g = gcd(xb, yb);

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll dx = xb / g;
    ll dy = yb / g;

    if (inbox(dx, dy, x1, y1, x2, y2) &&
        inbox(xb - dx, yb - dy, x1, y1, x2, y2)) {
        cout << "Yes";
    } else if (inbox(dx, dy, x1, y1, x2, y2)) {
        ll fst = min(x2 / dx, y2 / dy) + 1;
        cout << "No\n";
        cout << dx * fst << " " << dy * fst;
    } else {
        cout << "No\n";
        cout << dx << " " << dy;
    }
}
