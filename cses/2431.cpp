#include<bits/stdc++.h>

// Created by kobortor On 18:55:06 on 27-01-2024

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char solve(ll k) {
    k--;

    ll cnt = 9;
    ll len = 1;
    ll pow10 = 1;
    ll start = 0;
    while (k >= start + cnt * len) {
        start += cnt * len;
        cnt = cnt * 10;
        len++;
        pow10 *= 10;
    }

    ll val = (k - start) / len + pow10;
    return to_string(val)[(k - start) % len];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        cout << solve(k) << "\n";
    }
}
