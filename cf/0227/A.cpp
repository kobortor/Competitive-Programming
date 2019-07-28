#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll xa, ya;
    cin >> xa >> ya;

    ll xb, yb;
    cin >> xb >> yb;

    ll xc, yc;
    cin >> xc >> yc;

    ll xab = xb - xa;
    ll yab = yb - ya;

    ll xbc = xc - xb;
    ll ybc = yc - yb;

    if (xab * xbc + yab * ybc == 0) {
        if (xab * ybc - xbc * yab < 0) {
            cout << "RIGHT";
        } else {
            cout << "LEFT";
        }
    } else {
        cout << "TOWARDS";
    }
}
