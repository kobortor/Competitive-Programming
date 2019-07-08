#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, d;
    cin >> n >> d;

    vector<int> v(n);
    for (int &i : v) cin >> i;

    ll ans = 0;
    for (int a = 0, b = 0; a < n; a++) {
        while (b < n && v[b] - v[a] <= d) b++;

        ll cnt = b - a - 1;
        ans += cnt * (cnt - 1) / 2;
    }
    
    cout << ans;
}
