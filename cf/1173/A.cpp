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
    if (abs(x - y) > z) {
        if (x == y) {
            cout << 0;
        } else if (x > y) {
            cout << "+";
        } else {
            cout << "-";
        }
    } else {
        if (x == y && z == 0) {
            cout << 0;
        } else {
            cout << "?";
        }
    }
}
