#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll a, b;
    cin >> a >> b;

    if (a < b) {
        cout << -1;
        return 0;
    }

    double diff = (a + b) / 2.0;
    cout << fixed << setprecision(15) << diff / (ll)(diff / b);
}
