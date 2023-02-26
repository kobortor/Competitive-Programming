#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<string> rot(vector<string> a) {

    int n = a.size();
    vector<string> res = vector<string>(n, string(n, '?'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j][n - i - 1] = a[i][j];
        }
    }

    return res;

}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n; cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int,int>> pos;
    for (int rr = 0; rr < 4; rr++) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'X') continue;
                pos.push_back({i, j});
            }
        }

        a = rot(a);

    }

    vector<vector<int>> vis(n, vector<int>(n));

    for (auto [r, c] : pos) {
        vis[r][c] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                cout << "invalid grille\n";
                return 0;
            }
        }
    }

    if (pos.size() != n * n) {
        cout << "invalid grille\n";
        return 0;
    }

    vector<vector<char>> ans(n, vector<char>(n, '?'));

    string foo; cin >> foo;
    for (int i = 0; i < pos.size(); i++) {

        int R = pos[i].first, C = pos[i].second;
        ans[R][C] = foo[i];

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
    }
    cout << "\n";

}
