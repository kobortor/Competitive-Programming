#include<bits/stdc++.h>

// Created by kobortor On 22:39:34 on 08-08-2020

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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &ai : a) cin >> ai;
        for (int &bi : b) cin >> bi;

        int min_a = *min_element(allof(a));
        int min_b = *min_element(allof(b));

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(a[i] - min_a, b[i] - min_b);
        }

        cout << ans << "\n";
    }
}
