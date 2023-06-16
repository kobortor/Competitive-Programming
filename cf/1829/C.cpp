#include<bits/stdc++.h>

// Created by kobortor On 16:34:57 on 15-06-2023

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
        int n;
        cin >> n;

        map<string, int> mp;
        mp["00"] = mp["01"] = mp["10"] = mp["11"] = 1e9;
        while (n--) {
            int c;
            string s;
            cin >> c >> s;
            mp[s] = min(mp[s], c);
        }

        int ans = min(mp["11"], mp["01"] + mp["10"]);
        if (ans == 1e9) {
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
    }
}
