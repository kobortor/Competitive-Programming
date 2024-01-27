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
    ll tot = n * (n+1) / 2;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        tot -= x;
    }
    cout << tot << endl;
}
