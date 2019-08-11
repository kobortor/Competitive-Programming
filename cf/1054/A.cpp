#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;

    if (3 * t3 + abs(x - z) * t2 + abs(x - y) * t2 <= abs(x - y) * t1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
