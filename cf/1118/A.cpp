#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        ll n, a, b;
        cin >> n >> a >> b;
        b = min(2 * a, b);
        cout << n / 2 * b + n % 2 * a << "\n";
    }
}
