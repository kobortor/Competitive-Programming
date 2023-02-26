#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 250;

int nr, nc, n, m;

int DX = 7;
int DY = 4;

vector<int> xcoords, ycoords;
vector<pii> greens, reds;

int grid[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> nr >> nc >> n >> m;
    for (int i = 0; i < n; i++) {
        pii p;
        cin >> p.first >> p.second;
        p.first += DX;
        p.second += DY;

        greens.push_back(p);

        xcoords.push_back(p.first);

        ycoords.push_back(p.second);
    }
    for (int i = 0; i < m; i++) {
        pii p;
        cin >> p.first >> p.second;
        p.first += DX;
        p.second += DY;
        reds.push_back(p);

        xcoords.push_back(p.first);

        ycoords.push_back(p.second);
    }

    xcoords.push_back(-100);
    xcoords.push_back(0);
    xcoords.push_back(nr - 1);

    ycoords.push_back(-100);
    ycoords.push_back(0);
    ycoords.push_back(nc - 1);
    sort(allof(xcoords));
    sort(allof(ycoords));
    xcoords.erase(unique(allof(xcoords)), xcoords.end());
    ycoords.erase(unique(allof(ycoords)), ycoords.end());

    map<int, int> xmap, ymap;
    for (int i = 0; i < xcoords.size(); i++) {
        xmap[xcoords[i]] = i;
    }
    for (int i = 0; i < ycoords.size(); i++) {
        ymap[ycoords[i]] = i;
    }

    for (pii p : greens) {
        int diff = +1;
        grid[xmap[p.first]][ymap[p.second]] += diff;
    }
    for (pii p : reds) {
        int diff = -1;
        grid[xmap[p.first]][ymap[p.second]] += diff;
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            grid[i][j] += grid[i][j - 1];
        }
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            grid[i][j] += grid[i - 1][j];
        }
    }

    int lo_x = xmap[0];
    int hi_x = xmap[nr - 1] + 1;
    int lo_y = ymap[0];
    int hi_y = ymap[nc - 1] + 1;

    int ans = 0;
    for (int i0 = lo_x; i0 < hi_x; i0++) {
        for (int j0 = lo_y; j0 < hi_y; j0++) {
            for (int i1 = i0; i1 < hi_x; i1++) {
                for (int j1 = j0; j1 < hi_y; j1++) {
                    int tmp = grid[i1][j1] - grid[i0 - 1][j1] -
                              grid[i1][j0 - 1] + grid[i0 - 1][j0 - 1];
                    // if (tmp > ans) {
                    //     cout << i0 << " " << j0 << " to " << i1 << " " << j1
                    //          << endl;
                    // }
                    ans = max(ans, tmp);
                }
            }
        }
    }
    cout << n - ans << endl;
}
