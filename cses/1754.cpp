#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

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
        int a, b;
        cin >> a >> b;
        if (max(a, b) > 2 * min(a, b) || (a + b) % 3 != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
