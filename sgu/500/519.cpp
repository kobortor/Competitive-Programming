#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, M;
int grid[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= M; b++) {
            char c;
            cin >> c;
            grid[a][b] = c - '0';
        }
    }

    int ans = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= M; b++) {
            ans += max(0, grid[a][b] - grid[a - 1][b]);
            ans += max(0, grid[a][b] - grid[a + 1][b]);
            ans += max(0, grid[a][b] - grid[a][b - 1]);
            ans += max(0, grid[a][b] - grid[a][b + 1]);
            if (grid[a][b]) {
                ans += 2;
            }
        }
    }
    
    cout << ans;
}
