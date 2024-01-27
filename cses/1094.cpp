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

    int n;
    cin >> n;

    ll ans = 0, prv = -1, cur = -1;
    while (n--) {
        cin >> cur;
        if (cur < prv) {
            ans += prv - cur;
        } else {
            prv = cur;
        }
    }
    cout << ans << endl;
}
