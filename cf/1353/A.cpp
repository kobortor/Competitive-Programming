#include<bits/stdc++.h>

// Created by kobortor On 18:01:10 on 25-05-2020

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
        ll n, m;
        cin >> n >> m;
        if (n == 1) {
            cout << "0\n";
        } else if (n == 2) {
            cout << m << "\n";
        } else {
            cout << 2 * m << "\n";
        }
    }
}
