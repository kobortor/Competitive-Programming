#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int n, m;
char grid[MAXN][MAXN];

queue<int> q;
vector<int> rows[MAXN];
vector<int> cols[MAXN];

bool flag[MAXN * 2];

int sum0[MAXN];
bool no_zeros_in_range(int start, int len) {
    return sum0[start + len - 1] == sum0[start - 1];
}

bool dp1[MAXN][MAXN];
bool dp2[MAXN][MAXN];
int prefix[MAXN];

bool upgrade(char oldc, char newc) {
    if (newc == '?') return false;
    if (oldc == '?') return true;
    return false;
}

void transpose() {
    for (int i = 1; i <= max(n, m); i++) {
        for (int j = 1; j <= i; j++) {
            swap(grid[i][j], grid[j][i]);
        }
    }
    for (int i = 1; i <= max(n, m); i++) {
        swap(rows[i], cols[i]);
    }
    swap(n, m);
}

vector<int> update(int row) {
    for (int col = 1; col <= m; col++) {
        sum0[col] = sum0[col - 1] + (grid[row][col] == '.');
    }

    // dp[2][j] = where you can place like 
    // ..XXX..XXXX.
    //            ^
    // XXX..XXXX.
    //          ^
    memset(dp1, false, sizeof dp1);
    dp1[0][0] = true;
    for (int j = 1; j <= m; j++) {
        if (grid[row][j] == 'X') break;
        else dp1[0][j] = true;
    }
    for (int i = 0; i < rows[row].size(); i++) {
        int len = rows[row][i];
        for (int j = 1; j <= m; j++) {
            if (no_zeros_in_range(j, len) && grid[row][j + len] != 'X') {
                dp1[i + 1][j + len] |= dp1[i][j - 1];
            }
            if (grid[row][j] != 'X') {
                dp1[i + 1][j] |= dp1[i + 1][j - 1];
            }
        }
    }

    memset(dp2, false, sizeof dp2);
    dp2[rows[row].size()][m + 1] = true;

    for (int j = m; j >= 1; j--) {
        if (grid[row][j] == 'X') break;
        else dp2[rows[row].size()][j] = true;
    }
    for (int i = rows[row].size() - 1; i >= 0; i--) {
        int len = rows[row][i];
        for (int j = m - len + 1; j >= 1; j--) {
            if (no_zeros_in_range(j, len) && grid[row][j - 1] != 'X') {
                dp2[i][j - 1] |= dp2[i + 1][j + len];
            }
            if (grid[row][j - 1] != 'X') {
                dp2[i][j - 1] |= dp2[i][j];
            }
        }
    }

    string tmp_grid(m + 1, '.');
    for (int i = 0; i < rows[row].size(); i++) {
        memset(prefix, 0, sizeof prefix);
        int matched = 0;
        int len = rows[row][i];
        for (int j = 1; j + len - 1 <= m; j++) {
            if (dp1[i][j - 1] && dp2[i + 1][j + len] && no_zeros_in_range(j, len)) {
                matched++;
                prefix[j]++;
                prefix[j + len]--;
            }
        }
        for (int j = 1; j <= m; j++) {
            prefix[j] += prefix[j - 1];
            if (prefix[j] == matched) {
                tmp_grid[j] = 'X';
            } else if (prefix[j] > 0 && tmp_grid[j] != 'X') {
                tmp_grid[j] = '?';
            }
        }
    }

    vector<int> ans;

    for (int j = 1; j <= m; j++) {
        if (upgrade(grid[row][j], tmp_grid[j])) {
            ans.push_back(j);
            grid[row][j] = tmp_grid[j];
        }
    }
    
    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        while (p--) {
            int v;
            cin >> v;
            rows[i].push_back(v);
        }
    }

    for (int i = 1; i <= m; i++) {
        int p;
        cin >> p;
        while (p--) {
            int v;
            cin >> v;
            cols[i].push_back(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        flag[i] = true;
        q.push(i);
    }

    for (int i = 1; i <= m; i++) {
        flag[i + n] = true;
        q.push(i + n);
    }

    memset(grid, '?', sizeof grid);

    while (!q.empty()) {
        int fr = q.front();
        q.pop();
        if (!flag[fr]) continue;

        flag[fr] = false;

        if (fr <= n) {
            for (int col : update(fr)) {
                flag[col + n] = true;
                q.push(col + n);
            }
        } else {
            int col = fr - n;
            transpose();
            for (int row : update(col)) {
                flag[row] = true;
                q.push(row);
            }
            transpose();
        }
    }

    for (int i = 1; i <= n; i++) {
        grid[i][m + 1] = 0;
        cout << (grid[i] + 1) << "\n";
    }
}