#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll r, x, y, xp, yp;
    cin >> r >> x >> y >> xp >> yp;

    ll d = (x-xp)*(x-xp) + (y-yp)*(y-yp);
    cout << (ll)ceil(sqrt(d) / 2 / r);
}
