#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

// 2 + 4 + ... + 2n
ll even_sum(ll n) {
    return n * (n + 1) % mod;
}

// 1 + 3 + ... + (2n - 1)
ll odd_sum(ll n) {
    return (even_sum(n) - n + mod) % mod;
}

ll solve(ll n) {
    vector<ll> tot(2);
    tot[0] = tot[1] = 0;

    ll cur = 0;
    for (ll step = 0;; step++) {
        ll nxt = cur + (1ll << step);
        if (nxt >= n) {
            tot[(step + 1) % 2] += n - cur;
            tot[(step + 1) % 2] %= mod;
            break;
        } else {
            tot[(step + 1) % 2] += nxt - cur;
            tot[(step + 1) % 2] %= mod;
            cur = nxt;
        }
    }

    return (odd_sum(tot[1]) + even_sum(tot[0])) % mod;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll l, r;
    cin >> l >> r;
    cout << (solve(r) - solve(l - 1) + mod) % mod;
}
