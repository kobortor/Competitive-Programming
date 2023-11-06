#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("addictive.in", "r", stdin);
    freopen("addictive.out", "w", stdout);

    int n, m, c; cin >> n >> m >> c;

    vector<int> a(c);
    for (int &i : a) {
        cin >> i;
    }

    vector<vector<int>> ans(n, vector<int>(m));

    int ptr = 0;
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            while (a[ptr] == 0) ptr++;
            ans[i][j] = ptr + 1;
            a[ptr]--;
        }
    }

    for (auto v : ans) {
        for (int i : v)
            cout << i;
        cout << "\n";
    }

}
