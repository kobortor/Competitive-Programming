#include<bits/stdc++.h>

// Created by kobortor On 00:50:04 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string a, b;
    cin >> a >> b;
    if (a.size() == b.size()) {
        if (a == b) cout << -1;
        else cout << a.size();
    } else {
        cout << max(a.size(), b.size());
    }
}
