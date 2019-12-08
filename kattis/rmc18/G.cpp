#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;

    ll ans = N * (N - 1) / 2 + N - (N - K);
    ll prv = 0;

    while (K--) {
        ll h;
        cin >> h;

        ll tmp = h - prv - 1;
        ans -= tmp * (tmp - 1) / 2;

        prv = h;
    }

    ll tmp = N + 1 - prv - 1;
    ans -= tmp * (tmp - 1) / 2;

    cout << ans;
}
