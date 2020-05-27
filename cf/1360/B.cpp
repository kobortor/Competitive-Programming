#include<bits/stdc++.h>

// Created by kobortor On 16:21:11 on 27-05-2020

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

        vector<int> v(n);
        for (int &vi : v) cin >> vi;

        sort(allof(v));

        int ans = 1e9;
        for (int i = 1; i < n; i++) {
            ans = min(ans, v[i] - v[i - 1]);
        }

        cout << ans << "\n";
    }
}
