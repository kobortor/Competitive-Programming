#include<bits/stdc++.h>

// Created by kobortor On 01:04:46 on 26-05-2020

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
    vector<int> v(2 * n);
    for (int &vi : v) {
        cin >> vi;
    }

    sort(allof(v));
    if (v[0] == v.back()) {
        cout << -1;
    } else {
        for (int i : v) cout << i << " ";
    }
}
