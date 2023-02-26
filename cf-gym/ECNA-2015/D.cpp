#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int n, m;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(dist, 0x3f, sizeof dist);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (grid[i] + 1);
    }

    queue<pii> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'T' &&
                (grid[i - 1][j] != 'T' || grid[i + 1][j] != 'T' ||
                 grid[i][j - 1] != 'T' || grid[i][j + 1] != 'T')) {
                q.push({i, j});
                dist[i][j] = 1;
            }
        }
    }

    vector<pii> diff = {
        pii(-1, 0),
        pii(+1, 0),
        pii(0, -1),
        pii(0, +1)
    };

    while (!q.empty()) {
        pii top = q.front();
        q.pop();

        if (grid[top.first][top.second] != 'T') {
            continue;
        }

        for (pii d : diff) {
            pii nxt = {top.first + d.first, top.second + d.second};
            if (dist[top.first][top.second] + 1 < dist[nxt.first][nxt.second]) {
                dist[nxt.first][nxt.second] = dist[top.first][top.second] + 1;
                q.push(nxt);
            }
        }
    }

    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'T') {
                maxv = max(maxv, dist[i][j]);
            }
        }
    }

    int len = 3;
    if (maxv < 10) {
        len = 2;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'T') {
                string s = to_string(dist[i][j]);
                while (s.size() < len){ 
                    s = "." + s;
                }
                cout << s;
            } else {
                if (len == 2) {
                    cout << "..";
                } else {
                    cout << "...";
                }
            }
        }
        cout << "\n";
    }
}
