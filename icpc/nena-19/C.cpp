#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e7 + 7;

ll vals[MAXN];
ll prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll k, n;
    cin >> k >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
        prefix[i] = prefix[i - 1] + vals[i];
    }
    ll tot = prefix[n];
    for (int i = 1; i <= n; i++) {
        prefix[i + n] = prefix[i + n - 1] + vals[i];
    }

    if (tot % k != 0) {
        cout << "NO\n";
        return 0;
    }

    ll cut = tot / k;

    for (int i = 1; i <= n && prefix[i - 1] <= cut; i++) {
        int idx = i;
        bool good = true;
        for (int l = 0; l < k; l++) {
            int nxt = lower_bound(prefix, prefix + 2 * n + 1, prefix[idx - 1] + cut) - prefix;
            if (nxt == 2 * n + 1 || prefix[nxt] != prefix[idx - 1] + cut) {
                good = false;
                break;
            } else {
                idx = nxt + 1;
            }
        }
        if (good) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
