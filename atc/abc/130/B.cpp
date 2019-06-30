#include<iostream>
#include<utility>
#include<algorithm>
#include<iomanip>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll x, ll y) {
    while (x % y) {
        x %= y;
        swap(x, y);
    }
    return y;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll W, H, x, y;
    cin >> W >> H >> x >> y;
    cout << fixed << setprecision(15) << (double)W * H / 2.0 << " ";
    cout << (W == 2 * x && H == 2 * y);
}
