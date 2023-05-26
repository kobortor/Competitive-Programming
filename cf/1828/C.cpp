#include<bits/stdc++.h>

// Created by kobortor On 10:18:31 on 26-05-2023

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

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

        sort(allof(a));
        sort(allof(b));

        ll ans = 1;

        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && b[j] < a[i]) {
                j++;
            }
            ans = ans * (j - i) % mod;
        }
        cout << ans << "\n";
    }


}
