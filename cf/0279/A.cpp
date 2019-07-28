#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << 0;
        return 0;
    }

    int l = max(abs(x), abs(y));
    if (x == l) {
        if (y == -l) {
            cout << 4 * l;
        } else if (y == -l + 1) {
            cout << 4 * l - 4;
        } else {
            cout << 4 * l - 3;
        }
    } else if (y == l) {
        cout << 4 * l - 2;
    } else if (x == -l) {
        cout << 4 * l - 1;
    } else {
        cout << 4 * l;
    }
}
