#include<bits/stdc++.h>

// Created by kobortor On 02:02:57 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a, b;
    cin >> a >> b;
    int n = a + b + 1;
    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
        v[i - 1] = i;
    }

    reverse(v.begin() + a, v.end());
    for (int i : v) cout << i << " ";
}
