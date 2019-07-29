#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll x1, y1;
    cin >> x1 >> y1;

    ll x2, y2;
    cin >> x2 >> y2;

    ll n;
    cin >> n;

    ll ans = 0;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll s1 = a*x1 + b*y1 + c < 0;
        ll s2 = a*x2 + b*y2 + c < 0;
        if (s1 != s2) {
            ans++;
        }
    }
    cout << ans;
}
