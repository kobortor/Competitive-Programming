#include<bits/stdc++.h>

// Created by kobortor On 11:30:19 on 14-06-2023

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        k = min(k, 40ll);
        k = (1ll << k);
        cout << min(n + 1, k) << endl;
    }
}
