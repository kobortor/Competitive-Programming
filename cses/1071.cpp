#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;

        ll layer = max(x, y);
        ll id = x - y;
        if (layer % 2 == 0) {
            id = -id;
        }
        ll ans = (layer - 1) * (layer - 1) + layer + id;
        cout << ans << endl;
    }
}
