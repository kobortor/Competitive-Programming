#include<bits/stdc++.h>

// Created by kobortor On 10:06:00 on 15-06-2023

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
        cin >> n;

        int minv = 2e9;
        int maxv = 2e9;
        while (n--) {
            int x;
            cin >> x;
            minv = min(minv, x);
            maxv = max(maxv, x);
        }

        if (minv < 0) {
            cout << minv << "\n";
        } else {
            cout << maxv << "\n";
        }
    }
}
