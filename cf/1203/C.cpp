#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

ll gcd (ll a, ll b) {
    while (a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

bitset<MAXN> sieve;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    ll g = 0;
    while (n--) {
        ll x;
        cin >> x;
        g = gcd (g, x);
    }

    vector<ll> primes;
    for (int a = 2; a < MAXN; a++) {
        if (!sieve[a]) {
            primes.push_back(a);
            for (int b = 2 * a; b < MAXN; b += a) {
                sieve[b] = true;
            }
        }
    }

    ll ans = 1;
    for (ll p : primes) {
        ll tmp = 1;
        while (g % p == 0) {
            g /= p;
            tmp++;
        }
        ans = ans * tmp;
    }
    if (g != 1) {
        ans *= 2;
    }

    cout << ans;
}
