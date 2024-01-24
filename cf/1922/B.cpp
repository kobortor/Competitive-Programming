#include<bits/stdc++.h>

// Created by kobortor On 18:46:30 on 21-01-2024

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
        map<ll, ll> cnt;
        cin >> n;
        while (n--) {
            ll ai;
            cin >> ai;
            cnt[ai]++;
        }

        ll ans = 0;
        ll prv = 0;
        for (pll p : cnt) {
            ans += p.second * (p.second - 1) * (p.second - 2) / 6;
            ans += p.second * (p.second - 1) * prv / 2;
            prv += p.second;
        }
        cout << ans << "\n";
    }
}
