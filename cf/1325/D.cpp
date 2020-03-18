#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll u, v;
    cin >> u >> v;

    if ((u ^ v) % 2 || u > v) {
        cout << -1;
        return 0;
    }

    if (u == v) {
        if (u == 0) {
            cout << 0;
        } else {
            cout << 1 << '\n';
            cout << u;
        }
    } else {
        ll c = (v - u) / 2;
        if (c & u) {
            cout << 3 << '\n';
            cout << u << ' ' << c << ' ' << c;
        } else {
            cout << 2 << '\n';
            cout << (u | c) << ' ' << c;
        }
    }
}
