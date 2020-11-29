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
        int n, m;
        cin >> n >> m;

        int negative = 0;

        int tot = 0;
        int smallest = 1000;
        for (int i = 0, x; i < n * m; i++) {
            cin >> x;
            if (x < 0) {
                x *= -1;
                negative++;
            }

            smallest = min(smallest, x);

            tot += x;
        }

        if (negative % 2 == 0) {
            cout << tot << "\n";
        } else {
            cout << tot - 2 * smallest << "\n";
        }
    }
}
