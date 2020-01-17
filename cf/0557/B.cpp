#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, w;
    cin >> n >> w;

    vector<ll> cups(2 * n);
    for (ll &ai : cups) {
        cin >> ai;
    }

    sort(allof(cups));

    cout << fixed << setprecision(15) << 
        min(min(cups[0] * 3.0, cups[n] * 1.5) * n, static_cast<double>(w));
}
