#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<ll> primes;

const ll MAX = 1e9;

ll recur(int idx, ll cur) {
    if (idx == (int)primes.size()) {
        return 1;
    }

    if (primes[idx] * cur > MAX) {
        return 1;
    }

    ll ans = 0;
    do {
        ans += recur(idx + 1, cur);
        cur = cur * primes[idx];
    } while (cur <= MAX);

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    primes.push_back(2);
    for (int i = 3; i <= 100; i++) {
        bool is_prime = true;
        for (int p : primes) {
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
        }
    }

    cout << recur(0, 1) << endl;
}
