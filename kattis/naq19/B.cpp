#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N, M;
    cin >> N >> M;

    ll g = __gcd (N, M);
    ll n = N / g;
    ll m = M / g;

    if (n % 2 == 0 || m % 2 == 0) {
        cout << 0;
    } else {
        cout << g;
    }
}
