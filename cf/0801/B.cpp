#include<bits/stdc++.h>

// Created by kobortor On 23:45:11 on 25-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string x, y;
    cin >> x >> y;
    for (int i = 0; i < (int)x.size(); i++) {
        if (x[i] < y[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << y;
}
