#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

// gets number of liberties
int dfs(int r, int c, vector<string> &grid, set<pii> &liberties) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
        return 0;
    }
    if (grid[r][c] == '.') {
        liberties.insert({r, c});
    } else if (grid[r][c] == 'W') {
        int tot = 1;
        grid[r][c] = '#';
        tot += dfs(r - 1, c, grid, liberties);
        tot += dfs(r + 1, c, grid, liberties);
        tot += dfs(r, c - 1, grid, liberties);
        tot += dfs(r, c + 1, grid, liberties);
        return tot;
    }
    return 0;
}

int solve(vector<string> grid) {
    map<pii, int> captures;
    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            if (grid[r][c] == 'W') {
                set<pii> liberties;
                int sz = dfs(r, c, grid, liberties);
                if (liberties.size() == 1) {
                    captures[*liberties.begin()] += sz;
                }
            }
        }
    }
    int best = 0;
    for (auto [_, sz] : captures) {
        best = max(best, sz);
    }
    return best;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int r, c;
        cin >> r >> c;

        vector<string> grid;
        for (int i = 0; i < r; i++) {
            string s;
            cin >> s;
            grid.push_back(s);
        }

        cout << "Case #" << t << ": " << solve(grid) << endl;
    }
}