#include<bits/stdc++.h>

// Created by kobortor On 02:17:11 on 24-11-2020

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
        int x, y;
        cin >> x >> y;
        cout << 2 * min(x, y) + max((max(x, y) - min(x, y)) * 2 - 1, 0) << endl;
    }
}
