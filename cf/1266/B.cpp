#include<bits/stdc++.h>

// Created by kobortor On 01:20:31 on 26-05-2020

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
        ll x;
        cin >> x;

        bool ans = false;
        for (int i = 1; i <= 6; i++) {
            ans |= x >= (21 - i) && (x - (21 - i)) % 14 == 0;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}
