#include<bits/stdc++.h>

// Created by kobortor On 20:56:04 on 25-05-2020

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

    int pos_1 = 0;
    int pos_n = 0;
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        if (ai == 1) pos_1 = i;
        if (ai == n) pos_n = i;
    }

    int lo = min(pos_1, pos_n);
    int hi = max(pos_1, pos_n);

    cout << max(n - lo, hi - 1);
}
