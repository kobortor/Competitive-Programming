#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll a, b, c;
    cin >> a >> b >> c;

    if (a == b) {
        cout << a + b + c * 2;
    } else if (a > b) {
        cout << (b + 1) + b + c * 2;
    } else {
        cout << (a + 1) + a + c * 2;
    }
}
