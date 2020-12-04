#include<bits/stdc++.h>

// Created by kobortor On 00:07:32 on 04-12-2020

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
        int x;
        cin >> x;

        int tot = 0;
        int k = 0;
        while (tot < x) {
            k++;
            tot += k;
        }

        if (tot == x + 1) {
            cout << k + 1 << "\n";
        } else {
            cout << k << "\n";
        }
    }
}
