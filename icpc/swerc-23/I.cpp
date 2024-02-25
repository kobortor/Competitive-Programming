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

    int M, N;
    cin >> M >> N;

    ll totA = 0, totB = 0;
    while (M--) {
        ll x;
        cin >> x;
        totA += x + 1;
    }
    while (N--) {
        ll x;
        cin >> x;
        totB += x + 1;
    }
    if (totA > totB) {
        cout << "ALICE\n";
    } else if (totA < totB) {
        cout << "BOB\n";
    } else {
        cout << "TIED\n";
    }
}
