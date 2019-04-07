#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int R, C;
char grid[MAXN][MAXN];

//ir = initr
//pr = prevr
//nr = nextr
vector<pii> getpath (int ir, int ic, int r, int c) {
    vector<pii> path = {{ir, ic}};
    int pr = ir;
    int pc = ic;
    while (r != ir || c != ic) {
        path.push_back({r, c});
        int nr, nc;
        if (isupper(grid[r + (r - pr)][c + (c - pc)])) {
            nr = r + (r - pr);
            nc = c + (c - pc);
        } else if (isupper(grid[r + (c - pc)][c + (r - pr)])) { //turn 90 degrees
            nr = r + (c - pc);
            nc = c + (r - pr);
        } else { //turn other 90 degrees
            nr = r - (c - pc);
            nc = c - (r - pr);
        }
        tie(pr, pc) = {r, c};
        tie(r, c) = {nr, nc};
    }
    return path;
}

bool hasA[MAXN][MAXN];
bool hasB[MAXN][MAXN];

bool getout;
void predfs (int r, int c) {
    if (grid[r][c] == '%') {
        getout = true;
        return;
    } else if (grid[r][c] != '.') {
        return;
    } else {
        grid[r][c] = '#';
        predfs (r - 1, c - 1);
        predfs (r - 1, c);
        predfs (r - 1, c + 1);

        predfs (r, c - 1);
        predfs (r, c + 1);

        predfs (r + 1, c - 1);
        predfs (r + 1, c);
        predfs (r + 1, c + 1);
    }
}

void filldfs (int r, int c, bool arr[][MAXN]) {
    if (grid[r][c] == '%') {
        return;
    } else if (grid[r][c] != '#') {
        return;
    } else {
        grid[r][c] = ' ';
        arr[r][c] = true;
        filldfs (r - 1, c - 1, arr);
        filldfs (r - 1, c, arr);
        filldfs (r - 1, c + 1, arr);

        filldfs (r, c - 1, arr);
        filldfs (r, c + 1, arr);

        filldfs (r + 1, c - 1, arr);
        filldfs (r + 1, c, arr);
        filldfs (r + 1, c + 1, arr);
    }
}

void fillgrid (vector<pii> path, bool arr[][MAXN]) {
    for (int a = 1; a <= R; a++) {
        for (int b = 1; b <= C; b++) {
            grid[a][b] = '.';
        }
    }
    for (pii p : path) grid[p.first][p.second] = 'X';

    for (int a = 1; a <= R; a++) {
        for (int b = 1; b <= C; b++) {
            if (grid[a][b] == '.') {
                getout = false;
                predfs (a, b);

                if (!getout) {
                    filldfs(a, b, arr);
                }
            }
        }
    }
}

void solve (int initr, int initc) {
    vector<pii> pathA = getpath(initr, initc, initr + 1, initc);
    vector<pii> pathB = getpath(initr, initc, initr, initc + 1);

    for (pii p : pathA) {
        if (grid[p.first][p.second] == 'B') {
            swap (pathA, pathB);
            break;
        }
    }

    fillgrid (pathA, hasA);
    fillgrid (pathB, hasB);

    for (pii p : pathA) hasB[p.first][p.second] = false;
    for (pii p : pathB) hasA[p.first][p.second] = false;

    int ansA = 0, ansB = 0, ansAB = 0;
    for (int a = 1; a <= R; a++) {
        for (int b = 1; b <= C; b++) {
            if (hasA[a][b] && hasB[a][b]) {
                ansAB++;
            } else if (hasA[a][b]) {
                ansA++;
            } else if (hasB[a][b]) {
                ansB++;
            }
        }
    }

    cout << ansA << " " << ansB << " " << ansAB << endl;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(grid, '%', sizeof grid);
    cin >> R >> C;
    for (int a = 1; a <= R; a++) {
        cin >> (grid[a] + 1);
        grid[a][C + 1] = '%';
    }

    for (int a = 1; a <= R; a++) {
        for (int b = 1; b <= C; b++) {
            if (isupper(grid[a][b]) &&
                isupper(grid[a - 1][b]) &&
                isupper(grid[a + 1][b]) &&
                isupper(grid[a][b - 1]) &&
                isupper(grid[a][b + 1])) {
                solve (a, b);
                return 0;
            }
        }
    }
}

