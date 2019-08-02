#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, R, r;
    cin >> n >> R >> r;

    if (n == 1) {
        cout << (r <= R ? "YES" : "NO");
        return 0;
    }

    double d = R - r;

    double pi = acos(-1);
    double theta = 2 * pi / n;

    if (d * d + d * d - 2 * d * d * cos(theta) + 1e-5 < 4 * r * r) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}
