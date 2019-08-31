#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        ll x;
        cin >> x;

        ll cnt = 0;
        for (ll a = 2; a * a <= x; a++) {
            if (x % a == 0) {
                cnt++;

                if (a * a * a == x) cnt = 100;
            }
        }
        cout << (cnt == 1 ? "Yes" : "No") << endl;
    }
}
