#include<bits/stdc++.h>

// Created by kobortor On 23:42:26 on 04-12-2020

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

        map<int, vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            mp[x].push_back(i);
        }

        int ans = -1;
        for (auto [val, idxs] : mp) {
            if ((int)idxs.size() == 1) {
                ans = idxs[0];
                break;
            }
        }

        cout << ans << "\n";
    }
}
