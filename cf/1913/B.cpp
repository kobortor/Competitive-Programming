#include<bits/stdc++.h>

// Created by kobortor On 18:16:54 on 10-03-2024

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

        int cnt0 = count(allof(s), '0');
        int cnt1 = count(allof(s), '1');
        int minv = min(cnt0, cnt1);
        
        int c0 = 0, c1 = 0;
        int ans = s.size();
        for (char c : s) {
            if (c == '0') {
                c0++;
            } else {
                c1++;
            }
            if (max(c0, c1) <= minv) {
                ans = s.size() - (c0 + c1);
            }
        }
        cout << ans << endl;
    }
}
