#include<bits/stdc++.h>
#include <numeric>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

bool sieve[MAXN];
vector<int> primes;
vector<int> factors;
double pr_live[MAXN][MAXN];

vector<int> get_relevant_factors(int tot) {
    vector<int> ans;
    for (int f : factors) {
        if (__gcd(f, tot) != 1) {
            ans.push_back(f);
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 2; i <= 100; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            int p = i;
            int f = p;
            while (f * p < MAXN) {
                f *= p;
            }
            factors.push_back(f);
            for (int j = 0; j < f; j++) {
                pr_live[f][j] = 1.0 / f;
            }
            for (int j = 2 * i; j <= 100; j += i) {
                sieve[j] = true;
            }
        }
    }

    int n;
    cin >> n;

    // // Don't forget the case where it's always on or always off
    for (int i = 1; i <= n; i++) {
        int x, r, g;
        cin >> x >> r >> g;

        if (r == 0) {
            // always green

        } else if (g == 0) {
            // always red
        } else {
            vector<int> rf = get_relevant_factors(r + g);
            ll prod = 1;
            for (int j : rf) {
                prod *= j;
            }

            // double denom = accumulate();
            for (int j = 0; j < prod; j++) {
                int start_tm = (j - x) % prod;
                if (start_tm < 0) {
                    start_tm += prod;
                }

                bool is_red = (j < r);
                for (int f : rf) {
                    
                }
            }
            // prod <= 250k
        }
    }
}