#include<bits/stdc++.h>

// Created by kobortor On 00:47:26 on 14-09-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (string &s : grid) cin >> s;

    vector<vector<int>> soln(n, vector<int>(m));

    ll ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i + 2 < n && j - 1 >= 0 && j + 1 < m && 
                    grid[i][j] == grid[i + 1][j - 1] && 
                    grid[i][j] == grid[i + 1][j] && 
                    grid[i][j] == grid[i + 2][j] && 
                    grid[i][j] == grid[i + 1][j + 1]) {
                soln[i][j] = min(soln[i + 1][j - 1], min(soln[i + 2][j], soln[i + 1][j + 1])) + 1;
            } else {
                soln[i][j] = 1;
            }
            ans += soln[i][j];
        }
    }

    cout << ans;
}
