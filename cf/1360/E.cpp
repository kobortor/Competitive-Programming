#include<bits/stdc++.h>

// Created by kobortor On 00:37:41 on 27-05-2020

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

        vector<string> grid(n, string(n, '0'));
        for (string &s : grid) cin >> s;

        bool ans = true;

        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < n; j++) {
                if (grid[i][j] == '1') {
                    ans &= grid[i + 1][j] == '1' || grid[i][j + 1] == '1';
                }
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}
