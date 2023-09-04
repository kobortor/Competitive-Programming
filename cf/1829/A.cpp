#include<bits/stdc++.h>

// Created by kobortor On 16:28:15 on 15-06-2023

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
        string s;
        cin >> s;
        string cf = "codeforces";
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if (s[i] != cf[i]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
