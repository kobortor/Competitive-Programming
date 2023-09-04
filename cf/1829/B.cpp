#include<bits/stdc++.h>

// Created by kobortor On 16:29:37 on 15-06-2023

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

        int ans = 0;
        int prv = 1e9;
        for (int i = 0, ai; i < n; i++) {
            cin >> ai;
            if (ai == 0) {
                prv = min(prv, i);
                ans = max(ans, i - prv + 1);
            } else {
                prv = 1e9;
            }
        }

        cout << ans << "\n";
    }
}
