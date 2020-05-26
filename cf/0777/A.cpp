#include<bits/stdc++.h>

// Created by kobortor On 01:41:23 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, x;
    cin >> n >> x;
    n %= 6;

    while (n--) {
        if (n & 1) {
            if (x == 2) x = 1;
            else if (x == 1) x = 2;
        } else {
            if (x == 1) x = 0;
            else if (x == 0) x = 1;
        }
    }

    cout << x;
}
