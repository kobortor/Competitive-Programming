#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd (ll a, ll b) {
    while (a % b) {
        a %= b;
        swap (a, b);
    }
    return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<ll> v(n);
    for (ll &i : v) cin >> i;

    sort(allof(v));

    if (v[0] == v.back()) {
        cout << "0 0\n";
    } else {
        ll z = 0;
        for (int a = 1; a < n; a++) {
            if (v[a - 1] != v[a]) {
                z = gcd(z, v[a] - v[a - 1]);
            }
        }

        ll y = 0;
        for (int a = 0; a < n; a++) {
            y += (v.back() - v[a]) / z;
        }
        cout << y << " " << z;
    }
}
