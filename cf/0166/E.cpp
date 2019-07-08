#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    ll abc = 0, d = 1;
    while (n--) {
        ll nxt_abc = (3 * d + 2 * abc) % mod;
        ll nxt_d = abc % mod;

        d = nxt_d;
        abc = nxt_abc;
    }

    cout << d;
}
