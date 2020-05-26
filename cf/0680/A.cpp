#include<bits/stdc++.h>

// Created by kobortor On 23:23:38 on 25-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[101];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int sub = 0;

    vector<int> v(5);
    for (int &vi : v) cin >> vi;

    for (int i = 0; i < 5; i++) {
        int cnt = count(allof(v), v[i]);
        if (cnt >= 2) sub = max(sub, min(cnt, 3) * v[i]);
    }

    cout << accumulate(allof(v), 0) - sub;
}
