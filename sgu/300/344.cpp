#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M;

int adj[MAXN][MAXN];
char grid[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for (int a = 1; a <= N; a++) {
        cin >> (grid[a] + 1);
    }

    queue<pii> q;
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= M; b++) {
            if (grid[a][b] == 'X') {
                q.push({a, b});
            }
        }
    }

    int ans = 0;
    while (!q.empty()) {
        ans++;
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (++adj[r - 1][c] == 2 && grid[r - 1][c] == '.') {
            grid[r - 1][c] = 'X';
            q.push({r - 1, c});
        }

        if (++adj[r + 1][c] == 2 && grid[r + 1][c] == '.') {
            grid[r + 1][c] = 'X';
            q.push({r + 1, c});
        }

        if (++adj[r][c - 1] == 2 && grid[r][c - 1] == '.') {
            grid[r][c - 1] = 'X';
            q.push({r, c - 1});
        }

        if (++adj[r][c + 1] == 2 && grid[r][c + 1] == '.') {
            grid[r][c + 1] = 'X';
            q.push({r, c + 1});
        }
    }

    cout << ans;
}
