#include<bits/stdc++.h>

// Created by kobortor On 10:30:22 on 26-05-2023

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        vector<int> cnt(26);
        string s;
        cin >> s;
        for (char c : s) cnt[c - 'a']++;

        bool good = true;
        good &= count_if(allof(cnt), [](int x){return x % 2 == 1;}) <= 1;
        good &= count_if(allof(cnt), [](int x){return x >= 2;}) > 1;
        cout << (good ? "YES\n" : "NO\n");
    }
}
