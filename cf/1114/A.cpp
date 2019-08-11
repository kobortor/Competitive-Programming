#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int x, y, z;
    cin >> x >> y >> z;

    int a, b, c;
    cin >> a >> b >> c;

    if (a < x) {
        cout << "NO";
        return 0;
    }

    b += a - x;

    if (b < y) {
        cout << "NO";
        return 0;
    }

    c += b - y;

    if (c < z) {
        cout << "NO";
        return 0;
    }

    cout << "YES";
}
