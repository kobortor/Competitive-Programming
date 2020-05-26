#include<bits/stdc++.h>

// Created by kobortor On 00:08:43 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;
    cout << s;
    reverse(allof(s));
    cout << s;
}
