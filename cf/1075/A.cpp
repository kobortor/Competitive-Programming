#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;
    cin >> n;

    ll x, y;
    cin >> x >> y;

    if (min(abs(x - 1), abs(y - 1)) <= min(abs(x - n), abs(y - n))) {
        cout << "White";
    } else {
        cout << "Black";
    }
}
