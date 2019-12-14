#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

constexpr ll qpow(ll x, ll y) {
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

constexpr ll inv(ll x) {
    return qpow(x, mod - 2);
}

constexpr ll inv2 = inv(2);

int n, m;

vector<int> A, B;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        B.push_back(tmp);
    }

    ll cur_prob = 1;
    ll ans = 0;

    ll inv_m = inv(m);

    // Find probability that A > B
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            if (B[i] == 0) {
                // both unset
                ans = (ans + cur_prob * (1 - inv_m + mod) % mod * inv2) % mod;
            } else {
                // just A unset
                ans = (ans + cur_prob * inv_m % mod * (m - B[i])) % mod;
            }
            cur_prob = cur_prob * inv_m % mod;
        } else if (B[i] == 0) {
            ans = (ans + cur_prob * inv_m % mod * (A[i] - 1)) % mod;

            cur_prob = cur_prob * inv_m % mod;
        } else {
            // both already set
            if (A[i] == B[i]) {
                // do nothing
            } else if (A[i] < B[i]) {
                // no way we are bigger after this
                break;
            } else {
                // we are definitely bigger
                ans = (ans + cur_prob) % mod;
                break;
            }
        }
    }

    cout << ans;
}
