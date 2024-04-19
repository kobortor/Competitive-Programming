#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int score(vector<int> v, int cow) {
  // for (int vi : v) {
  //   cout << vi << " ";
  // }
  // cout << endl;
  int ans = 0;
  int best = v[0];
  for (int i = 1; i < v.size(); i++) {
    int nxt = max(best, v[i]);
    // cout << "nxt = " << nxt << endl;
    if (nxt == cow) {
      // cout << "Add " << i << endl;
      ans++;
    }
    best = nxt;
  }
  // cout << "score\n";
  
  return ans;
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;

    vector<int> v(n);
    for (int &vi : v) {
      cin >> vi;
    }

    int cow = v[p-1];

    int ans = 0;
    ans = max(ans, score(v, cow));

    swap(v[p-1], v[0]);
    ans = max(ans, score(v, cow));
    swap(v[p-1], v[0]);

    int first_better = -1;
    for (int i = 0; i < n; i++) {
      if (v[i] > cow) {
        first_better = i;
        break;
      }
    }

    if (first_better != -1) {
      swap(v[first_better], v[p-1]);
      ans = max(ans, score(v, cow));
      swap(v[first_better], v[p-1]);
    }

    cout << ans << "\n";
  }
}