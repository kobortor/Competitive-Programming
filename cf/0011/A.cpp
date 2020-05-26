#include<bits/stdc++.h>

// Created by kobortor On 00:01:15 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, d;
    cin >> n >> d;

    int ans = 0;
    int cur;
    cin >> cur;
    while (--n) {
        int nxt;
        cin >> nxt;
        if (nxt <= cur) {
            ans += (cur + d - nxt) / d;
            nxt += (cur + d - nxt) / d * d;
        }
        cur = nxt;
    }

    cout << ans;
}
