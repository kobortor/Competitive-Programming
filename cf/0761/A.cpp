#include<bits/stdc++.h>

// Created by kobortor On 01:02:07 on 26-05-2020

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
    
    cout << ((a || b) && abs(a - b) <= 1 ? "YES" : "NO");
}
