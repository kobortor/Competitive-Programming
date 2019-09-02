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

    vector<ll> v(n);
    for (ll &x : v) cin >> x;

    sort(allof(v));
    reverse(allof(v));

    vector<ll> used;

    ll ans = 0;
    for (ll bit = 62; bit >= 0; bit--) {
        for (int a = 0; a < (int)v.size(); a++) {
            if (v[a] & (1ll << bit)) {
                for (int b = 0; b < (int)v.size(); b++) {
                    if (a == b) continue;

                    if (v[b] & (1ll << bit)) {
                        v[b] ^= v[a];
                    }
                }
                for (ll &x : used) {
                    if (x & (1ll << bit)) {
                        x ^= v[a];
                    }
                }

                used.push_back(v[a]);
                v.erase(v.begin() + a);
                break;
            }
        }
    }

    for (ll x : used) ans ^= x;
    for (ll x : v) ans ^= x;

    cout << ans << endl;
}
