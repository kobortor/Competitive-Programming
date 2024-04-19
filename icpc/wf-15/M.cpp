#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct command {
  string tp;
  ll x, y;
  ll dx, dy;
  ll w, h;
};

string OPEN = "OPEN";
string CLOSE = "CLOSE";
string RESIZE = "RESIZE";
string MOVE = "MOVE";
vector<command> commands;

void fix(vector<ll> &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

bool contains(vector<ll> &xs, ll x) {
  return binary_search(xs.begin(), xs.end(), x);
}

string output;
pair<ll, ll> solve(vector<ll> xs, vector<ll> ys) {
  for (command cmd : commands){ 
    if (cmd.tp == OPEN) {
      if (!contains(xs, cmd.x) || !contains(ys, cmd.y)) return {cmd.x, cmd.y};
      if (!contains(xs, cmd.x + cmd.w) || !contains(ys, cmd.y + cmd.h))
          return {cmd.x + cmd.w, cmd.y + cmd.h};
    }
  }
  return {-1, -1};
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  string input;
  getline(cin, input);

  stringstream ss(input);
  ll xmax, ymax;
  ss >> xmax >> ymax;

  while (getline(cin, input)) {
    command cmd;
    stringstream ss2(input);
    ss2 >> cmd.tp;
    if (cmd.tp == OPEN) {
      ss2 >> cmd.x;
      ss2 >> cmd.y;
      ss2 >> cmd.w;
      ss2 >> cmd.h;
    } else if (cmd.tp == CLOSE) {
      ss2 >> cmd.x;
      ss2 >> cmd.y;
    } else if (cmd.tp == RESIZE) {
      ss2 >> cmd.x;
      ss2 >> cmd.y;
      ss2 >> cmd.w;
      ss2 >> cmd.h;
    } else {
      ss2 >> cmd.x;
      ss2 >> cmd.y;
      ss2 >> cmd.dx;
      ss2 >> cmd.dx;
    }
    commands.push_back(cmd);
  }

  vector<ll> xs, ys;
  xs.push_back(0);
  ys.push_back(0);

  xs.push_back(xmax);
  ys.push_back(ymax);

  while (true) {
    fix(xs);
    fix(ys);
    pll res = solve(xs, ys);
    if (res == pll(-1, -1)) {
      break;
    } else {
      if (res.first != -1) xs.push_back(res.first);
      if (res.second != -1) ys.push_back(res.second);
    }
  }
  cout << output << endl;
}