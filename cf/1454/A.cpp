#include<bits/stdc++.h>

// Created by kobortor On 23:41:19 on 04-12-2020

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
        cout << n;
        for (int i = 2; i <= n; i++) {
            cout << " " << i - 1;
        }
        cout << "\n";
    }
}
