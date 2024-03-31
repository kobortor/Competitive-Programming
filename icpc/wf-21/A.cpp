#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct wind {
  pii diff;
  vector<pii> boundaries;
  wind(pii d, vector<pii> b) {
    diff = d;
    boundaries = b;
  }
};

const int MAXN = 1005;
bool is_type[MAXN][MAXN][12];

int dx, dy, k;
vector<wind> winds;

pii operator+(pii p1, pii p2) {
  return {p1.first + p2.first, p1.second + p2.second};
}
pii operator-(pii p1, pii p2) {
  return {p1.first - p2.first, p1.second - p2.second};
}

bool within_bounds(pii p) {
  // cout << p.first << ", " << p.second << endl;
  return 0 <= p.first && p.first < dy && 0 <= p.second && p.second < dx;
}

vector<string> solve_min() {
  vector<string> out(dy, string(dx, '.'));

  queue<pii> bad;

  // We MUST set these things
  for (wind &w : winds) {
    for (pii p : w.boundaries) {
      out[p.first][p.second] = '#';
      bad.push(p);
    }
  }

  while (!bad.empty()) {
    pii p = bad.front();
    bad.pop();

    for (int wi = 0; wi < winds.size(); wi++) {
      bool is_inside = is_type[p.first][p.second][wi];
      if (is_inside) {
        // whatever
      } else {
        // I am not a boundary for this wind, so this must be filled
        pii q = p - winds[wi].diff;
        if (within_bounds(q) && out[q.first][q.second] == '.') {
          out[q.first][q.second] = '#';
          bad.push(q);
        }
      }
    }
  }

  return out;
}

vector<string> solve_max() {
  // Full set
  vector<string> out(dy, string(dx, '#'));

  queue<pii> bad;
  for (wind &w : winds) {
    for (pii p : w.boundaries) {
      pii q = p - w.diff;
      if (within_bounds(q) && out[q.first][q.second] == '#') {
        bad.push(q);
        out[q.first][q.second] = '.'; // Must not have this
      }
    }
  }
  for (int y = 0; y < dy; y++) {
    for (int x = 0; x < dx; x++) {
      pii p = {y, x};
      if (out[p.first][p.second] == '.') continue;

      for (int wi = 0; wi < winds.size(); wi++) {
        bool is_inside = is_type[p.first][p.second][wi];
        pii q = p - winds[wi].diff;
        if (!is_inside) {
          if (!within_bounds(q) || out[q.first][q.second] == '.') {
            out[p.first][p.second] = '.';
            bad.push(p);
            break;
          }
        }
      }
    }
  }

  while (!bad.empty()) {
    pii p = bad.front();
    bad.pop();

    for (int wi = 0; wi < winds.size(); wi++) {
      pii q = p + winds[wi].diff;
      if (!within_bounds(q)) continue;

      bool is_inside = is_type[q.first][q.second][wi];
      // I am now a empty square, make sure the opposites aren't mistakenly filled
      if (is_inside) {
        // ok, whatever
      } else {
        if (out[q.first][q.second] == '#') {
          out[q.first][q.second] = '.';
          bad.push(q);
        }
      }
    }
  }

  return out;
}

typedef pair<double, double> P;
ostream& operator<<(ostream& os, P p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

P linePerp(const P& a, const P& b, const P& p) {
  // returns the projection of p onto the line connecting a and b
  P dir = {b.x - a.x, b.y - a.y};
  double dir_len = sqrt(dir.x * dir.x + dir.y * dir.y);
  dir.x /= dir_len;
  dir.y /= dir_len;

  P dir_norm = {-dir.y, dir.x};
  double p_dir = p.x * dir.x + p.y * dir.y;
  double p_dir_norm = a.x * dir_norm.x + a.y * dir_norm.y;
  
  P q = {
    p_dir * dir.x  + p_dir_norm * dir_norm.x,
    p_dir * dir.y + p_dir_norm * dir_norm.y,
  };

  return q;
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  P out = linePerp(P(0, 1), P(1, 0), P(-1, -2));
  cout << out << endl;

  // cin >> dx >> dy >> k;

  // for (int i = 0; i < k; i++) {
  //   int wx, wy;
  //   cin >> wx >> wy;

  //   vector<pii> boundaries;
  //   int b;
  //   cin >> b;
  //   while (b--) {
  //     int x, y;
  //     cin >> x >> y;

  //     x--;
  //     y--;

  //     is_type[y][x][i] = true;
  //     boundaries.push_back(pii(y, x));
  //   }
  //   winds.push_back({pii(wy, wx), boundaries});
  // }

  // for (string s : solve_min()) {
  //   cout << s << "\n";
  // }
  // cout << "\n";
  // for (string s : solve_max()) {
  //   cout << s << "\n";
  // }
}