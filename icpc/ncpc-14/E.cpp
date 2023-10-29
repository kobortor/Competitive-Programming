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

    vector<ll> v(n);
    for (ll &vi : v) {
        cin >> vi;
    }
    sort(allof(v));

    ll ans = n;
    for (int i = 0; i < n; i++) {
        ans = min(ans, (n - 1 - i) + v[i]);
    }
    cout << ans << endl;
}
