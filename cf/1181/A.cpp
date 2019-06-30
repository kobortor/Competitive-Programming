#include <iostream>
#include <utility>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll x, y, z;
    cin >> x >> y >> z;

    cout << (x + y) / z << " " << (x + y < z || x / z + y / z == (x + y) / z ? 0 : min((x + z - 1) / z * z - x, (y + z - 1) / z * z - y));
}
