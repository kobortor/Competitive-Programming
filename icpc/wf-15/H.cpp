#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

typedef vector<int> vi;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
const ll INF = numeric_limits<ll>::max() / 4;

typedef double T;
vector<T> tridiagonal(vector<T> diag, const vector<T>& super,
 const vector<T> & sub, vector<T> b) {
  int n = sz(b); vi tr(n);
  for (int i = 0; i < n - 1; i++) {
    if (abs(diag[i]) < 1e-9 * abs(super[i])) {
      b[i + 1] -= b[i] * diag[i + 1] / super[i];
      if (i + 2 < n) b[i + 2] -= b[i] * sub[i+1] / super[i];
      diag[i+1] = sub[i]; tr[++i] = 1;
    } else {
      diag[i+1] -= super[i] * sub[i] / diag[i];
      b[i+1] -= b[i] * sub[i] / diag[i];
    }
  }

  for (int i = n; i--; ) {
    if (tr[i]) {
      swap(b[i], b[i-1]);
      diag[i-1] = diag[i];
      b[i] /= super[i-1];
    } else {
      b[i] /= diag[i];
      if (i) b[i-1] -= b[i] * super[i-1];
    }
  }
  return b;
}

vector<T> solve(int n, double A, double B, double C, double z) {
  vector<T> b(n); b.back() = z;
  return tridiagonal(vector<T>(n, B), vector<T>(n - 1, C), vector<T>(n - 1, A), b);
}

double sq(double x){return x * x;}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  double w, h;
  int n;
  cin >> w >> h >> n;

  double alpha = h / w;
  double A = alpha * alpha - 1;
  double B = 2;
  double C = alpha * alpha - 1;
  
  double z = -C * w;
  vector<T> ans = solve(n, A, B, C, z);

  double totcost = 0;
  for (double x : ans) {
    totcost += sq(alpha * x);
  }
  totcost += sq(h);

  for (int i = -1; i < (int)ans.size(); i++) {
    double x1 = i == -1 ? 0 : ans[i];
    double x2 = i + 1 < ans.size() ? ans[i+1] : w;
    double y1 = x1 * alpha;
    double y2 = x2 * alpha;

    double z = x1 + (x2 - x1 + (y1 + y2)) / 2 - y1;
    totcost += sq(z - x1 + y1) - sq(y1);
    totcost += sq(x2 - z + y2) - sq(y2);
  }
  cout << fixed << setprecision(10) << totcost / 2 << endl;
  for (int i = 0; i < (int)ans.size() && i < 10; i++) {
    cout << fixed << setprecision(10) << ans[i] << endl;
  }
}