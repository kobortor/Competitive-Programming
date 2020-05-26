#include<bits/stdc++.h>

// Created by kobortor On 20:31:23 on 25-05-2020

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
        
        vector<int> x(n), y(n);
        for (int &xi : x) cin >> xi;
        for (int &yi : y) cin >> yi;

        sort(allof(x));
        sort(allof(y));

        for (int i = 0; i < n; i++) {
            cout << x[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << y[i] << " ";
        }
        cout << "\n";
    }
}
