#include<bits/stdc++.h>

// Created by kobortor On 00:58:00 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, a;
    cin >> n >> a;
    vector<int> v(n);
    for (int &vi : v) cin >> vi;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = 2 * (a - 1) - i;
        if (!(0 <= j && j < n) || v[j] == 1) {
            ans += v[i] == 1;
        }
    }

    cout << ans;
}
