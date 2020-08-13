#include<bits/stdc++.h>

// Created by kobortor On 22:35:47 on 08-08-2020

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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &ai : a) cin >> ai;

        sort(allof(a));

        bool good = true;
        for (int i = 1; i < n; i++) {
            good &= a[i] - a[i - 1] <= 1;
        }

        cout << (good ? "YES\n" : "NO\n");
    }
}
