#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct box {
    ll l, u, r, d;

    void read () {
        cin >> l >> u >> r >> d;
    }

    void bound (box other) {
        l = max(l, other.l);
        u = max(u, other.u);
        r = min(r, other.r);
        d = min(d, other.d);

        l = min(l, r);
        u = min(u, d);
    }

    ll area () {
        return (r - l) * (d - u);
    }
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    box w, b1, b2;
    w.read();
    b1.read();
    b2.read();

    b1.bound(w);
    b2.bound(w);

    box inter = b1;
    inter.bound(b2);

    if (b1.area() + b2.area() - inter.area() == w.area()) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}
