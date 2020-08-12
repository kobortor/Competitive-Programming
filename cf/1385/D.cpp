#include<bits/stdc++.h>

// Created by kobortor On 16:53:43 on 11-08-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<tuple<int, int, char>, int> cache;

int n;
string s;

int solve(int l, int r, char c) {
    if (l + 1 == r) {
        return c != s[l];
    }

    tuple<int, int, char> key{l, r, c};
    if (cache.count(key)) {
        return cache[key];
    }

    int mid = (l + r) / 2;

    int lft_flat = (mid - l) - count(s.begin() + l, s.begin() + mid, c);
    int rht_flat = (r - mid) - count(s.begin() + mid, s.begin() + r, c);
    
    return cache[key] = min(
            solve(mid, r, c + 1) + lft_flat,
            solve(l, mid, c + 1) + rht_flat);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> s;

        cache.clear();
        cout << solve(0, n, 'a') << "\n";
    }
}
