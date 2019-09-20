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
        ll n, m;
        cin >> n >> m;

        ll times = n / m;

        ll tens = 0;
        for (int a = 1; a <= 10; a++) {
            tens += a * m % 10;
        }

        ll ans = tens * (times / 10);
        for (int a = 1; a <= times % 10; a++) {
            ans += a * m % 10;
        }

        cout << ans << endl;
    }
}
