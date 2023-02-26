#include <bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

const int MAXN = 5005;

typedef pair<int, int> pii;

int n, w;
string words[MAXN];
int max_width[MAXN][MAXN];

int prv[MAXN];
int cost[MAXN];

bool good(int rows) {
    memset(cost, 0x3f, sizeof cost);
    cost[0] = 0;

    for (int j = 1; j <= n; j++) {
        for (int i = j; i >= 1 && j - i + 1 <= rows; i--) {
            int new_cost = cost[i - 1] + max_width[i][j] + 1;
            cost[j] = min(cost[j], new_cost);
        }
    }
    return cost[n] - 1 <= w;
}

void output(int rows) {
    memset(cost, 0x3f, sizeof cost);
    cost[0] = 0;

    for (int j = 1; j <= n; j++) {
        for (int i = j; i >= 1 && j - i + 1 <= rows; i--) {
            int new_cost = cost[i - 1] + max_width[i][j] + 1;
            if (new_cost < cost[j]) {
                cost[j] = new_cost;
                prv[j] = i;
            }
        }
    }

    vector<int> widths;
    vector<pii> groups;
    int idx = n;
    while (idx != 0) {
        widths.push_back(max_width[prv[idx]][idx]);
        groups.push_back({prv[idx], idx});
        idx = prv[idx] - 1;
    }

    reverse(allof(widths));
    reverse(allof(groups));

    // int total_widths = std::accumulate(widths.begin(), widths.end(), -1) + widths.size();
    cout << rows << " " << widths.size() << "\n";
    for (int w : widths) {
        cout << w << " ";
    }
    cout << "\n";

    vector<vector<string>> answer_grid(rows, vector<string>(widths.size()));
    for (int i = 0; i < (int)groups.size(); i++) {
        for (int j = groups[i].first; j <= groups[i].second; j++) {
            answer_grid[j - groups[i].first][i] = words[j];
        }
    }

    for (int i = 0; i < (int)answer_grid.size(); i++) {
        for (int j = 0; j < (int)answer_grid[i].size(); j++) {
            cout << answer_grid[i][j];
            for (int k = answer_grid[i][j].size(); k < widths[j]; k++) {
                cout << " ";
            }
            cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> words[i];
    }
    for (int i = 1; i <= n; i++) {
        int maxw = -1;
        for (int j = i; j <= n; j++) {
            maxw = max(maxw, (int)words[j].size());
            max_width[i][j] = maxw;
            // cout << "max_width[" << i << "][" << j << "] = " << maxw << endl;
        }
    }

    int lo = 0, hi = 1e6 + 6;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (good(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    output(hi + 1);
    // cout << hi + 1 << "\n";
}