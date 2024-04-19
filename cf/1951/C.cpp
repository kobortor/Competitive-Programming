#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll cost(vector<ll> tickets, vector<ll> purchase) {
  ll ans = 0;
  ll raise = 0;
  for (int i = 0; i < tickets.size(); i++) {
    ans += purchase[i] * (tickets[i] + raise);
    raise += purchase[i];
  }
  return ans;
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> tickets(n);
    for (ll &ti : tickets) {
      cin >> ti;
    }

    vector<ll> purchase(n, 0);

    // priority_queue<pll, vector<pll>, greater<pll>> pq;
    priority_queue<pll> pq;
    for (int i = 0; i < n; i++) {
      ll tmp = m;
      ll value = -(tmp * tmp + 2 * tickets[i] * tmp);
      // cout << i << ": " << value << endl;
      pq.push({value, i});
    }

    ll rem = k;
    while (rem >= m) {
      auto [value, idx] = pq.top();
      pq.pop();
      purchase[idx] += m;
      rem -= m;
    }

    if (rem != 0) {
      vector<pll> cand;
      for (int i = 0; i < n; i++) {
        if (purchase[i] != 0) {
          continue;
        }
        ll value = -(rem * rem + 2 * tickets[i] * rem);
        cand.push_back({value, i});
      }
      auto [value, idx] = *max_element(cand.begin(), cand.end());
      purchase[idx] += rem;
      rem -= rem;
    }

    // for (ll p : purchase) {
    //   cout << p << " ";
    // }
    // cout << endl;

    cout << cost(tickets, purchase) << endl;
  }
}