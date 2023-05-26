#include<bits/stdc++.h>

// Created by kobortor On 10:10:24 on 26-05-2023

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

        for (int i = 1; i <= n; i++) {
            cout << 2 * i << " ";
        }
        cout << "\n";
    }
}
