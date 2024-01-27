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

    int n;
    cin >> n;

    if (n == 4) {
        cout << "2 4 1 3\n";
        return 0;
    }

    vector<int> v(n);
    int cur = 0;
    for (int i = 0; i < n; i += 2) {
        v[i] = ++cur;
    }
    for (int i = 1; i < n; i += 2) {
        v[i] = ++cur;
    }
    for (int i = 0; i + 1 < n; i++) {
        if (abs(v[i] - v[i+1]) == 1) {
            cout << "NO SOLUTION\n";
            return 0;
        }
    }
    for (int i : v) {
        cout << i << " ";
    }
}
