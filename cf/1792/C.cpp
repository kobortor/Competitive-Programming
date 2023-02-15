#include<bits/stdc++.h>

// Created by kobortor On 18:45:16 on 15-02-2023

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        set<pii> st;
        map<int, int> lookup;
        for (int i = 1, pi; i <= n; i++) {
            cin >> pi;
            st.insert({i, pi});
            lookup[pi] = i;
        }

        int ans = 0;
        int i = 1, j = n;
        while (i < j) {
            if (st.begin()->second == i && prev(st.end())->second == j) {
                st.erase(st.begin());
                st.erase(prev(st.end()));
            } else {
                int x = lookup[i];
                int y = lookup[j];
                st.erase({x, i});
                st.erase({y, j});
                ans = i;
            }
            i++;
            j--;
        }
        cout << ans << "\n";
    }
}
