#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<ll> mods = {
    // 998244353,
    (ll)1e9 + 7, (ll)1e9 + 9, (ll)1e9 + 21, (ll)1e9 + 33};

ll qpow(ll x, ll y, ll mod) {
    ll ans = 1;
    x %= mod;
    while (y) {
        if (y & 1) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        y /= 2;
    }
    return ans;
}

ll inv(ll x, ll mod) { return qpow(x, mod - 2, mod); }

vector<pll> get_input() {
    ll n;
    cin >> n;
    vector<pll> v(n);
    for (pll &p : v) {
        cin >> p.first >> p.second;
    }
    return v;
}

ll brute_force_hash(vector<pll> v) {
    mods.push_back(998244353);
    vector<vector<ll>> hashes;
    hashes.push_back(vector<ll>(mods.size()));
    vector<ll> prefix(mods.size());
    ll ans = 0;
    for (auto [p, q] : v) {
        for (int i = 0; i < mods.size(); i++) {
            ll mod = mods[i];
            prefix[i] += p * inv(q, mod);
            prefix[i] %= mod;
        }
        for (vector<ll> prv : hashes) {
            ll diff = prefix[0] - prv[0];
            diff %= mods[0];
            if (diff < 0) diff += mods[0];

            bool good = true;
            for (int i = 0; i < mods.size(); i++) {
                ll d2 = prefix[i] - prv[i];
                d2 %= mods[i];
                if (d2 < 0) d2 += mods[i];
                if (d2 != diff) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans++;
            }
        }
        hashes.push_back(prefix);
    }
    mods.pop_back();
    return ans;
}

ll smart_solve(vector<pll> v) {
    map<vector<ll>, ll> diff_lookup;

    diff_lookup[vector<ll>(mods.size() - 1)] = 1;

    ll ans = 0;
    vector<ll> pre(mods.size());

    for (auto [p, q] : v) {
        for (int i = 0; i < mods.size(); i++) {
            ll mod = mods[i];
            ll v = p * inv(q, mod) % mod;
            pre[i] += v;
            pre[i] %= mod;
        }

        vector<ll> prefix;
        for (int i = 1; i < mods.size(); i++) {
            ll tmp = pre[i] - pre[0];
            tmp %= mods[i];
            if (tmp < 0) tmp += mods[i];
            prefix.push_back(tmp);
        }

        ans += diff_lookup[prefix];

        diff_lookup[prefix]++;
    }
    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    bool first = true;
    bool repeat = false;
    while (first || repeat) {
        first = false;
        vector<pll> input = get_input();
        cout << smart_solve(input) << endl;
    }
}
