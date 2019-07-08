#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<ll, ll> c1, c2;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        c1[x + y]++;
        c2[x - y]++;
    }

    ll ans = 0;
    for (pll p : c1) ans += p.second * (p.second - 1) / 2;
    for (pll p : c2) ans += p.second * (p.second - 1) / 2;

    cout << ans;
}
