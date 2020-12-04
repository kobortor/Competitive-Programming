#include<bits/stdc++.h>

// Created by kobortor On 00:34:16 on 04-12-2020

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
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int &ai : a) cin >> ai;

        int ans = 0;
        for (int &ai : a) {
            if (is_sorted(allof(a))) {
                break;
            }
            if (ai > x) {
                ans++;
                swap(ai, x);
            }
        }

        if (is_sorted(allof(a))) {
            cout << ans << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
