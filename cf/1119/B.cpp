#include<bits/stdc++.h>

// Created by kobortor On 14:43:41 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, h;
    cin >> n >> h;

    vector<int> v(n);
    for (int &vi : v) cin >> vi;

    int lo = 0, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        vector<int> u(v.begin(), v.begin() + mid);
        sort(allof(u));
        reverse(allof(u));

        if (u.size() % 2 == 1) u.push_back(u.back());

        ll ans = 0;
        for (int i = 0; i < (int)u.size(); i += 2) {
            ans += u[i];
        }

        if (ans <= h) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << hi;
}
