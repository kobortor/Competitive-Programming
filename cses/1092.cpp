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

    ll n;
    cin >> n;

    ll tot = n * (n + 1) / 2;
    if (tot % 2 == 1) {
        cout << "NO\n";
        return 0;
    }
    vector<int> v1, v2;
    ll rem = tot / 2;
    for (int i = n; i >= 1; i--) {
        if (rem >= i) {
            rem -= i;
            v1.push_back(i);
        } else {
            v2.push_back(i);
        }
    }
    if (rem != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << v1.size() << "\n";
    for (int i : v1) {
        cout << i << " ";
    }
    cout << "\n";
    cout << v2.size() << "\n";
    for (int i : v2) {
        cout << i << " ";
    }
    cout << "\n";
}
