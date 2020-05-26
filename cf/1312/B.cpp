#include<bits/stdc++.h>

// Created by kobortor On 00:46:12 on 26-05-2020

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
        vector<int> v(n);
        for (int &vi : v) cin >> vi;
        sort(allof(v));
        reverse(allof(v));
        for (int i : v) cout << i << " ";
        cout << "\n";
    }
}
