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
        ll x;
        cin >> x;

        int ans = 0;
        while (x % 5 == 0) {
            x /= 5;
            ans += 3;
        }
        while (x % 3 == 0) {
            x /= 3;
            ans += 2;
        }
        while (x % 2 == 0) {
            x /= 2;
            ans += 1;
        }

        if (x == 1) cout << ans << endl;
        else cout << -1 << endl;
    }
}
