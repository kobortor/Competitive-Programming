#include<bits/stdc++.h>

// Created by kobortor On 01:18:12 on 26-05-2020

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

    // initial stone
    // later stone
    // travel to each
    // travel from shorter side back
    // collect all coins
    cout << 1 + n + (n - 1) + min(n - k, k - 1) + n;
}
