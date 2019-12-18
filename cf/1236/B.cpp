#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

ll qpow(ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1) {
            ans = ans * x % mod;
        }

        x = x * x % mod;
        y >>= 1;
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    cout << qpow(qpow(2, m) - 1 + mod, n);
}
