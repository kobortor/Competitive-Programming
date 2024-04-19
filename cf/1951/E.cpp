#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool is_palin(const string &s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

vector<pair<pii, char>> decompose(string s) {
  vector<pair<pii, char>> blocks;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n && s[j+1] == s[j]) {
      j++;
    }
    blocks.push_back({pii(i, j), s[i]});
    i = j;
  }
  return blocks;
}

vector<pii> solve(string s) {
  if (!is_palin(s)) {
    return {pii(0, s.size() - 1)};
  }

  auto blocks = decompose(s);
  vector<pii> ans;
  if (blocks.size() % 2 == 0) {
    for (int i = 0; i < blocks.size(); i += 2) {
      ans.push_back(pii(blocks[i].first.first, blocks[i+1].first.second));
    }
    return ans;
  }

  // odd, is a palindrome
  if (blocks.size() == 1) return {}; // No hope

  set<char> chars;
  for (auto au : blocks) {
    chars.insert(au.second);
  }
  // if not all abababa
  if (chars.size() > 2) {
    // try to split A...BC...A
    // for (int i = 1; i + 1 < blocks.size(); i++) {
    //   if (blocks[0].second != blocks[i].second && blocks[i+1].second != blocks.back().second) {
    //     // OK
    //     ans.push_back(pii(blocks[0].first.first, blocks[i].first.second));
    //     ans.push_back(pii(blocks[i+1].first.first, blocks.back().first.second));
    //     return ans;
    //   }
    // }

    // try to split AB..BAC...A
    ans.push_back(pii(blocks[0].first.first, blocks[1].first.second));
    ans.push_back(pii(blocks[2].first.first, blocks.back().first.second));
    // AB is obviously not palindrome
    // The number of Bs on the right side interlaced with A is wrong (cut by C)
    return ans;
  }

  char A = blocks[0].second;
  char B = blocks[1].second;

  // otherwise all ABABABABA
  for (int i = 1; i + 1 < blocks.size(); i++) {
    if (blocks[i].second == B) {
      int wid = blocks[i].first.second - blocks[i].first.first + 1;
      if (wid > 1) {
        // cut B in half
        ans.push_back(pii(blocks[0].first.first, blocks[i].first.first));
        ans.push_back(pii(blocks[i].first.first + 1, blocks.back().first.second));
        return ans;
      }
    }

    int wid_lft = blocks[0].first.second - blocks[0].first.first  + 1;
    int wid_rht = blocks.back().first.second - blocks.back().first.first + 1;
    // cout << "Sides " << wid_lft << " " << wid_rht << endl;
    if (blocks[i].second == A) {
      int wid = blocks[i].first.second - blocks[i].first.first + 1;
      for (int j = 0; j <= wid; j++) {
        // cout << "Try " << j << endl;
        int lft = j;
        int rht = wid - j;
        if (lft != wid_lft && rht != wid_rht) {
          ans.push_back(
              pii(blocks[0].first.first, blocks[i].first.first - 1 + lft));
          ans.push_back(
              pii(blocks[i].first.first + lft, blocks.back().first.second));
        // cout << "Exit " << __LINE__ << endl;
          return ans;
        }
      }
    }
  }

  // Otherwise all the middle A and Bs are length 1
  // We seem to be doomed
  return {};
}

typedef vector<int> vi;
#define sz(s) ((int)(s).size())
#define rep(i,a,b) for (int i=a; i<b;i++)
void manacher(const string &s) {
  int n = sz(s);
  vi p[2] = {vi(n + 1), vi(n)};
  rep(z, 0, 2) for (int i = 0, l = 0, r = 0; i < n; i++) {
    int t = r - i + !z;
    if (i < r)
      p[z][i] = min(t, p[z][l + t]);
    int L = i - p[z][i], R = i + p[z][i] - !z;
    while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
      p[z][i]++, L--, R++;
    if (R > r)
      l = L, r = R;
  }
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    vector<pii> ans = solve(s);

    if (ans.empty()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << ans.size() << "\n";
      for (pii p : ans) {
        cout << s.substr(p.first, p.second - p.first + 1) << " ";
      }
      cout << "\n";
    }
    // cout << flush;
  }
}