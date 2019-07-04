#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;
bool sieve[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int a = 2; a < MAXN; a++) {
        if (!sieve[a]) {
            for (int b = 2 * a; b < MAXN; b += a) {
                sieve[b] = true;
            }
        }
    }

    int n;
    cin >> n;
    for (int a = 2; n - a >= 2; a++) {
        if (sieve[a] && sieve[n - a]) {
            cout << a << " " << n - a;
            return 0;
        }
    }
}
