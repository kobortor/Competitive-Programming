#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
const int MAXN = 5e5 + 5;

ll pow2[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow2[i] = pow2[i - 1] * 2;
        if (pow2[i] >= mod) {
            pow2[i] -= mod;
        }
    }

    string s;
    cin >> s;

    int k = 0, zeros = 0;
    for (char c : s) {
        if (c == '?') {
            k++;
        } else if (c == '0') {
            zeros++;
        }
    }

    int k_remain = k;

    ll ans = 0;
    for (char c : s) {
        if (c == '1') {
            ans = (ans + pow2[k] * zeros) % mod;
            if (k != 0) {
                ans = (ans + k_remain * pow2[k - 1]) % mod;
            }
        } else if (c == '?') {
            k_remain--;
            if (k != 0) {
                ans = (ans + pow2[k - 1] * zeros) % mod;
                if (k != 1) {
                    ans = (ans + k_remain * pow2[k - 2]) % mod;
                }
            }
        } else if (c == '0') {
            zeros--;
        }
    }

    cout << ans;
}
