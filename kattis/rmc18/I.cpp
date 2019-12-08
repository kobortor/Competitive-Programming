#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    while (n != 0) {
        m = min(m, (n - 1) * (n - 1 - 1) / 2 + 1);
        ans += m;
        n--;
        m--;
    }

    cout << ans;
}
