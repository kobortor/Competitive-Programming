#include<bits/stdc++.h>

// Created by kobortor On 14:09:16 on 28-07-2020

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
        array<int, 3> arr;
        for (int &i : arr) cin >> i;

        int mx = *max_element(allof(arr));
        int cnt = count(allof(arr), mx);
        if (cnt == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int mn_idx = min_element(allof(arr)) - arr.begin();
            int mn = arr[mn_idx];

            if (mn_idx == 0) {
                cout << mn << " " << mn << " " << mx << "\n";
            } else if (mn_idx == 1) {
                cout << mn << " " << mx << " " << mn << "\n";
            } else if (mn_idx == 2) {
                cout << mx << " " << mn << " " << mn << "\n";
            }
        }
    }
}
