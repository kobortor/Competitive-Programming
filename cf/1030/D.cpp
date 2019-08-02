#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) {
    while (a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m, k;
    cin >> n >> m >> k;

    ll g = gcd(n * m, k);

    ll area;
    if (k == g) {
        area = n * m / g * 2;
    } else if (k == g * 2) {
        area = n * m / g;
    } else {
        cout << "NO";
        return 0;
    }

    if (area > n * m) {
        cout << "NO";
        return 0;
    }
    
    ll gn = gcd(area, n);
    ll gm = gcd(area, m);
    if (m >= area / gn) {
        cout << "YES\n";
        cout << "0 0\n";
        cout << gn << " 0\n";
        cout << "0 " << area / gn << "\n";
    } else if (n >= area / gm) {
        cout << "YES\n";
        cout << "0 0\n";
        cout << area / gm << " 0\n";
        cout << "0 " << gm << "\n";
    } else {
        cout << "NO";
    }
}
