#include "bits/stdc++.h"

#define ll long long

using namespace std;
const int MAXN = 110;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int n, m;
string a[MAXN];
int cnt[MAXN][MAXN];
int ty[MAXN][MAXN];
int vis[MAXN][MAXN];
int vals[MAXN][MAXN];

int good(int r, int c) {
  return (r >= 0 && c >= 0 && r < n && c < m);
}

void dfs(int r, int c, int x) {
  ty[r][c] = ty[r][c] | x;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (!good(nr, nc)) continue;
    if (a[nr][nc] == '.') continue;
    if (ty[nr][nc] & x) continue;
    if (cnt[nr][nc] != 2) continue;

    dfs(nr, nc, x);

  }
}

void ffill(int r, int c, int bad, int &cn, int tp) {

  cn++;
  vis[r][c] = 1;
  vals[r][c] = vals[r][c] | tp;

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (!good(nr, nc)) continue;
    if (ty[nr][nc] & bad) continue;
    if (vis[nr][nc]) continue;
    ffill(nr, nc, bad, cn, tp);
  }

}

int get(int bad) {

  memset(vis, 0, sizeof(vis));

  int foo;
  ffill(0, 0, bad, foo, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j]) continue;
      if (ty[i][j] == bad) continue;
      foo = 0;
      ffill(i, j, bad, foo, bad);
      return foo;
    }
  }

  cout << "uh oh" << endl;
  assert(false);
  return 0;

}

int main() {

  cin >> n >> m;
  m += 2;

  int ra = -1, ca = -1;
  int rb = -1, cb = -1;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = "." + a[i] + ".";
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'A') {
        ra = i;
        ca = j;
      }
      if (a[i][j] == 'B') {
        rb = i;
        cb = j;
      }
    }
  }

  n += 2;
  a[0] = string(m, '.');
  a[n - 1] = string(m, '.');

  vector<pair<int,int>> isect;
  for (int i = 1; i + 1 < n; i++) {
    for (int j = 1; j + 1 < m; j++) {
      if (a[i][j] != '.') {
        for (int x = 0; x < 4; x++) {
          int nr = i + dr[x];
          int nc = j + dc[x];
          cnt[i][j] += (a[nr][nc] != '.');
        }
        if (cnt[i][j] == 4) {
          isect.push_back({i, j});
        }
      }
    }
  }

  assert(isect.size() == 2);

  dfs(ra, ca, 1);
  dfs(rb, cb, 2);

  vector<array<int,3>> tf;

  for (auto [r, c] : isect) {

    ty[r][c] = 3;

    if (ty[r - 1][c]) {
      tf.push_back({r + 1, c, ty[r - 1][c]});
    }
    else {
      tf.push_back({r - 1, c, ty[r + 1][c]});
    }

    if (ty[r][c - 1]) {
      tf.push_back({r, c + 1, ty[r][c - 1]});
    }
    else {
      tf.push_back({r, c - 1, ty[r][c + 1]});
    }

  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << ty[i][j];
  //   }
  //   cout << "\n";
  // }

  int ofill[2] = {};

  for (auto [r, c, col] : tf) {
    if (ty[r][c] & col) continue;
    dfs(r, c, col);
  }

  // cout << "am here" << endl;

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << ty[i][j];
  //   }
  //   cout << "\n";
  // }

  int A = get(1);
  int B = get(2);

  // cout << "got " << A << " " << B << " filled in " << ofill[0] << " " << ofill[1] << "\n";

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << vals[i][j];
  //   }
  //   cout << "\n";
  // }

  vector<pair<int,int>> cs;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vals[i][j] == 3) {
        cs.push_back({i, j});
      }
    }
  }
  
  for (auto [r, c] : cs) {
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        vals[r + i][c + j] = 0;
      }
    }
  }

  // cout << "\n";
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << vals[i][j];
  //   }
  //   cout << "\n";
  // }

  int C = get(3);
  
  int tots[4] = {};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tots[vals[i][j]]++;
    }
  }

  tots[3] = cs.size();

  cout << tots[1] << " " << tots[2] << " " << tots[3] << "\n";

}

/*

7 7
AXXXX..
X...X..
X.XXXXX
X.X.X.X
XXXXX.X
..X...X
..XXXXB

11 13
XXXXXXA......
X.....X......
X..XXXXXXXXX.
X..X..X....X.
X..X..XXX..XX
X..B....X...X
X..X.XXXX...X
X..X.X......X
XX.XXXXXX...X
.X...X..X.XXX
.XXXXX..XXX..

*/