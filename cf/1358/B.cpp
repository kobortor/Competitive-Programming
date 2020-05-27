#include<bits/stdc++.h>

// Created by kobortor On 15:28:14 on 27-05-2020

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

        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (v[i] <= i + 1) {
                ans = i + 2;
            }
        }
        cout << ans << "\n";
    }
}
