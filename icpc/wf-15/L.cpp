#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

typedef vector<int> vi;

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
const ll INF = numeric_limits<ll>::max() / 4;

const int MAXN = 25;

double pr[4];
ll nck[MAXN][MAXN];

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  for (int i = 0; i < MAXN; i++) {
    nck[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      nck[i][j] += nck[i - 1][j - 1] + nck[i - 1][j];
    }
  }

  int n;
  cin >> n;
  for (int i = 0; i < 4; i++) {
    cin >> pr[i];
  }

  // prob, multiplicity
  minheap<pair<double, ll>> huffman;

  for (int n0 = 0; n0 <= n; n0++) {
    for (int n1 = 0; n0 + n1 <= n; n1++) {
      for (int n2 = 0; n0 + n1 + n2 <= n; n2++) { 
        int n3 = n - (n0 + n1 + n2);
        ll cnt = 1;
        cnt *= nck[n][n0];
        cnt *= nck[n - n0][n1];
        cnt *= nck[n - n0 - n1][n2];

        double prob = 1;
        prob *= pow(pr[0], n0);
        prob *= pow(pr[1], n1);
        prob *= pow(pr[2], n2);
        prob *= pow(pr[3], n3);

        huffman.push({prob, cnt});
      }
    }
  }

  double ans = 0;
  while (huffman.top().second > 1 || huffman.size() > 1) {
    pair<double, ll> top = huffman.top();
    // cout << "Testing " << top.first << " " << top.second << endl;
    huffman.pop();
    if (top.second % 2 == 0) {
      ans += top.first * (top.second / 2) * 2;
      huffman.push({top.first * 2, top.second / 2});
    } else {
      if (top.second >= 2) {
        // self matches
        ans += top.first * (top.second / 2) * 2;
        huffman.push({top.first * 2, top.second / 2});
      }

      pair<double, ll> nxt = huffman.top();
      huffman.pop();

      if (nxt.second == 1) {
        ans += top.first + nxt.first;
        huffman.push({top.first + nxt.first, 1});
      } else {
        ans += top.first + nxt.first;
        huffman.push({top.first + nxt.first, 1});
        huffman.push({nxt.first, nxt.second - 1});
      }
    }
  }

  cout << fixed << setprecision(9) << ans << endl;
}