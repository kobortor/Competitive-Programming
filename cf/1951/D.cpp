#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

map<pll, bool> cache;
map<pll, ll> path;
bool solve(int n, int k) {
  if (cache.count(pll(n, k))) {
    return cache[pll(n, k)];
  }

  if (k == 0) return true;

  bool good = false;
  for (int px = 1; px <= n; px++) {
  // for (int px = n; px >= 1; px--) {
    int buy = n / px;
    if (buy > k) continue;

    if (solve(n - px * buy, k - buy)) {
      path[pll(n, k)] = px;
      good = true;
      break;
    }
  }
  return cache[pll(n, k)] = good;
}

bool check(ll n, ll k, vector<ll> prices) {
  for (ll p : prices) {
    ll buy = n / p;
    k -= buy;
    n -= buy * p;
  }
  // cout << "End with " << k << endl;
  return k == 0;
}

// bool trysolve(int n, int k) {
//   if (n == k) {
//     return check(n, k, {n});
//   }

//   while (k) {
//     vector<int> prices;
//   }
// }

int main() {
  cin.tie(0);
  cin.sync_with_stdio(false);

  // int MAX = 15;
  // for (int n = 1; n <= MAX; n++) {
  //   for (int k = 1; k <= MAX; k++) {
  //     bool x2 = (n == k || n >= k * 2 - 1);
  //     if (!x2) {
  //       continue;
  //     }
  //     // bool good = trysolve(n, k);
  //     ll guess;
  //     if (n == k) {
  //       guess = 1;
  //     } else {
  //       // guess = n - k + 1;
  //       guess = n / (k + 1) + 1;
  //     }
  //     solve(n, k);
  //     cout << n << ", " << k << " = " << path[pll(n ,k)] << " " << guess << endl;
  //     if (path[pll(n, k)] != guess) {
  //       cout << "ERROR\n";
  //     }
  //     // bool x1 = solve(n, k);
  //     // if (x1 != x2) {
  //     //   cout << "ERROR " << n << " " << k << endl;
  //     // }
  //     // cout << (x1 ? '#' : '.');
  //   }
  //   // cout << endl;
  // }

  // return 0;

  int t;
  cin >> t;
  while (t--) {
    ll old_n, old_k;

    ll n, k;
    cin >> n >> k;
    old_n = n;
    old_k = k;
    bool possible = (n == k || n >= k * 2 - 1);
    if (!possible) {
      cout << "NO\n";
      continue;
    }

    vector<ll> prices;
    while (k) {
      ll px = (n == k) ? 1 : (n - k + 1);
      prices.push_back(px);
      // cout << px << endl;

      ll buy = n / px;
      n -= buy * px;
      k -= buy;
    }

    cout << "YES\n";
    cout << prices.size() << "\n";
    for (ll px : prices) {
      cout << px << " ";
    }
    cout << "\n";
  }
}