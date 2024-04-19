#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

char flip(char c) {
  if (c == '1')
    return '0';
  else
    return '1';
}

void answer(bool good) {
  if (good) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    vector<int> on;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        on.push_back(i);
      }
    }

    if (on.size() % 2 == 1) {
      cout << "NO\n";
    } else {
      bool good = true;
      for (int i = 0; i < on.size() / 2; i++) {
        int j = i + on.size() / 2;
        good &= on[j] - on[i] > 1;
      }
      if (good) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}