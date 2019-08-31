#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll fact (ll n) { return n == 0 ? 1 : n * fact (n - 1); }
ll nck (ll n, ll k) { return fact(n) / fact(k) / fact(n - k); }

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    if (k > n) {
        cout << 0;
    } else {
        cout << nck (n, k) * fact(n) / fact(n - k);
    }
}
