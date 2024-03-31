#include <bits/stdc++.h>

using namespace std;

typedef complex<double> C;
typedef vector<double> vd;

int rp, cp;
int rq, cq;

#define sz(x) ((x).size())

typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()
#define rep(i, x, y) for(int i = x; i < y; i++)

void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T> &v) {
  for (const T &t : v) {
    os << t << " ";
  }
  return os;
}

vector<int> get_match_1d(vector<int> orig, vector<int> pat) {
  // Returns all locations where pat matches orig, ignore 0s
  vector<int> ans;
  vector<double> remap(101);
  for (double &x : remap) {
    x = rand() / (double)RAND_MAX;
  }
  remap[0] = 0;

  vd orig_double(orig.begin(), orig.end());
  vd pat_double(pat.begin(), pat.end());
  for (double &x : orig_double) x = remap[int(x)];
  for (double &x : pat_double) x = remap[int(x)];

  vd rand_vec(pat.size());
  for (double &x : rand_vec) {
    x = rand() / (double)RAND_MAX;
  }
  for (int i = 0; i < pat.size(); i++) {
    if (pat[i] == 0) {
      rand_vec[i] = 0;
    }
  }

  reverse(rand_vec.begin(), rand_vec.end());

  vd out = conv(orig_double, rand_vec);
  vd target = conv(pat_double, rand_vec);

  double want = target[pat.size() - 1];
  for (int i = 0; i < orig.size(); i++) {
    if (i % cq + cp - 1 < cq && abs(out[i + pat.size() - 1] - want) < 1e-6) {
      ans.push_back(i);
    }
  }

  return ans;
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  cin >> rp >> cp;

  vector<vector<int>> pat;
  for (int r = 0; r < rp; r++) {
    vector<int> v;
    for (int c = 0; c < cp; c++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    pat.push_back(v);
  }

  cin >> rq >> cq;
  vector<vector<int>> grid;
  for (int r = 0; r < rq; r++) {
    vector<int> v;
    for (int c = 0; c < cq; c++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    grid.push_back(v);
  }

  vector<int> pat_flat;
  for (int r = 0; r < rp; r++) {
    if (r != 0) {
      for (int extra = 0; cp + extra < cq; extra++) {
        pat_flat.push_back(0);
      }
    }
    for (int x : pat[r]) {
      pat_flat.push_back(x);
    }
  }

  vector<int> grid_flat;
  for (vector<int> v : grid) {
    for (int x : v) {
      grid_flat.push_back(x);
    }
  }

  vector<int> ans = get_match_1d(grid_flat, pat_flat);
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int i : ans) {
    int r = i / cq;
    int c = i % cq;
    cout << r + 1 << " " << c + 1 << "\n";
  }
}