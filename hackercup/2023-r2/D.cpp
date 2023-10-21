#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e6 + 6;
const int MAXK = 21;

const ll MOD = 1e9 + 7;

int my_gcd(int x, int y) {
    if (x == 0) return y;
    if (y == 0) return x;
    return __gcd(x, y);
}

vector<int> factorize(int n) {
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

vector<pii> prime_factor(int n) {
    vector<pii> ans;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back({i, 0});
            while (n % i == 0) {
                n /= i;
                ans.back().second++;
            }
        }
    }
    if (n != 1) {
        ans.push_back({n, 1});
    }
    return ans;
}

ll qpow(ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1) {
            ans = ans * x % MOD;
        }
        x = x * x % MOD;
        y /= 2;
    }
    return ans;
}

ll inv(ll x) {
    return qpow(x, MOD - 2);
}

ll fact[MAXN];

ll nck(ll n, ll k) {
    if (n < k) return 0;
    return fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD;
}

ll npk(ll n, ll k) {
    if (n < k) return 0;
    return fact[n] * inv(fact[n - k]) % MOD;
}

vector<vector<int>> get_paths(vector<int> A, int rem) {
    if (rem == 0) {
        return {{}};
    }
    vector<vector<int>> ans;
    for (int i = 0; i < A.size(); i++) {
        vector<int> B = A;
        B.erase(B.begin() + i);
        for (vector<int> v : get_paths(B, rem - 1)) {
            v.push_back(A[i]);
            ans.push_back(v);
        }
    }
    return ans;
}

ll A[MAXN];
ll freq[MAXN];

int mobius[MAXN];
int sieve[MAXN];

int main() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    fill(mobius, mobius + MAXN, 1);
    for (ll i = 2; i < MAXN; i++) {
        if (sieve[i]) continue;

        // is prime
        for (ll j = i; j < MAXN; j += i) {
            sieve[j] = true;
            mobius[j] *= -1;
        }
        for (ll j = i * i; j < MAXN; j += i * i) {
            mobius[j] = 0;
        }
    }

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, K, D;
        cin >> N >> K >> D;

        memset(freq, 0, sizeof freq);
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            freq[A[i]]++;
        }

        for (int i = 1; i < MAXN; i++) {
            for (int j = i * 2; j < MAXN; j += i) {
                freq[i] += freq[j];
                freq[i] %= MOD;
            }
        }

        ll ans = 0;

        for (int d : factorize(D)) { 
            for (int x = 1; x * d < MAXN; x++) {
                ll u = npk(freq[x * d], K);
                ll v = mobius[x];
                if (u && v) {
                    // cout << "Add " << u << " * " << v << endl;
                }
                ans += u * v;
                ans %= MOD;
                if (ans < 0) {
                    ans += MOD;
                }
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}