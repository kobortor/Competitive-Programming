#include<bits/stdc++.h>

// Created by kobortor On 11:30:09 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    int ans = -1;

    int hi = 0, lo = 1e6;
    while (n--) {
        int cur;
        cin >> cur;
        if (cur > hi || cur < lo) {
            ans++;
        }

        hi = max(hi, cur);
        lo = min(lo, cur);
    }

    cout << ans;
}
