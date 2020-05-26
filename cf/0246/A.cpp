#include<bits/stdc++.h>

// Created by kobortor On 23:52:01 on 25-05-2020

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

    if (n <= 2) {
        cout << -1;
    } else {
        for (int i = n; i >= 1; i--) cout << i << " ";
    }
}
