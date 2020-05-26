#include<bits/stdc++.h>

// Created by kobortor On 23:34:48 on 25-05-2020

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
    vector<int> v(n);
    for (int &vi : v) cin >> vi;

    int mx = *max_element(allof(v));
    int mn = *min_element(allof(v));

    if (mx == mn) cout << 0;
    else cout << v.size() - count(allof(v), mx) - count(allof(v), mn);
}
