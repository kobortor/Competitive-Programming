#include<bits/stdc++.h>

// Created by kobortor On 22:53:16 on 08-08-2020

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

        vector<int> w(n);
        map<int, int> cnt;
        for (int &wi : w) {
            cin >> wi;
            cnt[wi]++;
        }

        set<int> sums;
        for (int i : w) {
            for (int j : w) {
                sums.insert(i + j);
            }
        }

        int ans = 0;
        for (int s : sums) {
            int tmp = 0;
            for (auto [v, c] : cnt) {
                if (v < s - v) {
                    tmp += min(c, cnt[s - v]);
                } else if (v == s - v) {
                    tmp += c / 2;
                }
            }

            ans = max(ans, tmp);
        }

        cout << ans << '\n';
    }
}
