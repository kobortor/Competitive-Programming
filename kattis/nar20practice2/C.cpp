#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

unordered_set<ll> values;

ll gcd(ll a, ll b) {
    while (a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<ll> v1 = {1}, v2;
    while (n--) {
        ll x;
        cin >> x;
        for (ll y : v1) {
            v2.push_back(gcd(x, y));
        }
        v2.push_back(x);

        sort(allof(v2));
        v2.erase(unique(allof(v2)), v2.end());

        for (ll y : v2) {
            values.insert(y);
        }

        v1.clear();
        swap(v1, v2);
    }

    cout << values.size();
}
