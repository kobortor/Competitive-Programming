#include<bits/stdc++.h>

// Created by kobortor On 11:28:40 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int y;
    cin >> y;
    while (++y) {
        string s = to_string(y);
        sort(allof(s));
        if (unique(allof(s)) == s.end()) break;
    }

    cout << y;
}
