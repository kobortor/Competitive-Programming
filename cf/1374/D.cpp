#include<bits/stdc++.h>

// Created by kobortor On 23:38:00 on 03-07-2020

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
        ll n, k;
        cin >> n >> k;

        map<ll, ll> cnt;

        for (ll i = 0; i < n; i++) {
            ll v;
            cin >> v;
            v = (k - (v % k)) % k;

            if (v) cnt[v]++;
        }

        ll max_pos, max_val = 0;
        for (pii p : cnt) {
            if (p.second >= max_val) {
                max_pos = p.first;
                max_val = p.second;
            }
        }

        if (max_val == 0) {
            cout << "0\n";
        } else {
            cout << (max_pos + 1) + k * (max_val - 1) << "\n";
        }
    }
}
