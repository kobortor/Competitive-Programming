#include<bits/stdc++.h>

// Created by kobortor On 00:25:38 on 27-05-2020

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

    vector<ll> v(n);
    for (ll &vi : v) cin >> vi;

    sort(allof(v));
    cout << accumulate(v.begin(), v.begin() + k, 0ll);
}
