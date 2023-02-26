#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int dsu[MAXN * MAXN];
bool has_exit[MAXN * MAXN];
int dot[MAXN * MAXN];

char grid[MAXN][MAXN];
bool is_exit[MAXN][MAXN];

int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    dsu[fx] = fy;
    has_exit[fy] |= has_exit[fx];
    dot[fy] += dot[fx];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 0; i < MAXN * MAXN; i++) {
        dsu[i] = i;
    }

    int N, M;
    cin >> N >> M;

    string s;
    getline(cin, s);

    for (int i = 0; i < N; i++) {
        getline(cin, s);
        for (int j = 0; j < M; j++) {
            grid[i][j] = s[j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c = grid[i][j];
            if ('A' <= c && c <= 'W') {
                has_exit[i * M + j] = true;
                is_exit[i][j] = true;
            }
            if (c == '.') {
                dot[i * M + j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'X') {
                continue;
            }

            if (i + 1 < N && grid[i + 1][j] != 'X' &&
                !(is_exit[i][j] && is_exit[i + 1][j])) {
                merge(i * M + j, (i + 1) * M + j);
            }
            if (j + 1 < M && grid[i][j + 1] != 'X' &&
                !(is_exit[i][j] && is_exit[i][j + 1])) {
                merge(i * M + j, i * M + (j + 1));
            }
        }
    }

    int reached = 0;
    int missing = 0;
    for (int i = 0; i < N * M; i++) {
        if (dsu[i] == i && dot[i] != 0) {
            if (has_exit[i]) {
                reached++;
                // cout << "Add at " << i / M << ", " << i % M << " at " << grid[i / M][i % M] << endl;
            } else {
                // cout << "Missing at " << i / M << ", " << i % M << " at " << grid[i / M][i % M] << endl;
                missing += dot[i];
            }
        }
    }
    cout << reached << " " << missing << endl;
}
