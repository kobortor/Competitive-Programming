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

    vector<int> v(n);
    for (int &vi : v) cin >> vi;

    sort(allof(v));
    reverse(allof(v));

    int alice = 0, bob = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            alice += v[i];
        } else {
            bob += v[i];
        }
    }

    cout << alice << " " << bob << endl;

}
