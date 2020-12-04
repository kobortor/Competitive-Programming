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
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        vector<int> b(n);

        for (int &ai : a) cin >> ai;
        for (int &bi : b) cin >> bi;

        sort(allof(a));
        sort(allof(b));
        reverse(allof(b));

        bool good = true;
        for (int i = 0; i < n; i++) {
            good &= (a[i] + b[i] <= x);
        }

        cout << (good ? "Yes\n" : "No\n");
    }
}
