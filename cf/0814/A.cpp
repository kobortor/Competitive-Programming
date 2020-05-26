#include<bits/stdc++.h>

// Created by kobortor On 23:46:53 on 25-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &vi : v) cin >> vi;

    vector<int> w(n);
    for (int &wi : w) cin >> wi;
    sort(allof(w));
    for (int &vi : v) if (vi == 0) { vi = w.back(); w.pop_back(); }

    cout << (is_sorted(allof(v)) ? "No" : "Yes");
}
