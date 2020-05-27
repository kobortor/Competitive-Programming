#include<bits/stdc++.h>

// Created by kobortor On 12:17:10 on 27-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int ans = n;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i <= k) ans = min(ans, n / i);
                if (n / i <= k) ans = min(ans, i);
            }
        }

        cout << ans << "\n";
    }
}
