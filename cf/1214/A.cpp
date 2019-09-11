#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, d, e;
    cin >> n >> d >> e;

    int ans = INT_MAX;
    e *= 5;
    for (int a = 0; a < d && n - a * e >= 0; a++) {
        ans = min (ans, (n - a * e) % d);
    }

    cout << ans;
}
