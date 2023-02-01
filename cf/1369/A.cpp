#include<bits/stdc++.h>

// Created by kobortor On 11:32:03 on 01-02-2023

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
    while (n--) {
        int k;
        cin >> k;
        cout << (k % 4 ? "NO\n" : "YES\n");
    }
}
