#include<bits/stdc++.h>

// Created by kobortor On 01:51:10 on 26-05-2020

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

    if (n == 1 || (n == 2 && v[0] == v[1])) {
        cout << -1;
    } else {
        cout << "1\n" << min_element(allof(v)) - v.begin() + 1 << " ";
    }
}
