#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define int long long

typedef vector<int> vi;

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
const ll INF = numeric_limits<ll>::max() / 4;

vi num, st;
vector<vector<pii>> ed;
vector<pii> edges;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
  int me = num[at] = ++Time, e, y, top = me;
  for (auto pa : ed[at]) if (pa.second != par) {
    tie(y, e) = pa;
    if (num[y]) {
      top = min(top, num[y]);
      if (num[y] < me) {
        st.push_back(e);
      }
    } else {
      int si = sz(st);
      int up = dfs(y, e, f);
      top = min(top, up);
      if (up == me) {
        st.push_back(e);
        f(vi(st.begin() + si, st.end()));
        st.resize(si);
      } else if (up < me) {
        st.push_back(e);
      } else {
        // is a bridge
      }
    }
  }
  return top;
}

template<class F>
void bicomps(F f) {
  num.assign(sz(ed), 0);
  for (int i = 0; i < sz(ed); i++) {
    if (!num[i]) {
      dfs(i, -1, f);
    }
  }
}

vector<int> factors;

void myfunc(vi v) {
  set<int> uniq;
  for (int i : v) {
    uniq.insert(edges[i].first);
    uniq.insert(edges[i].second);
    // cout << "See " << edges[i].first << " " << edges[i].second << endl;
  }
  if (uniq.size() != v.size()) {
    factors.push_back(1);// not a simple cycle
  } else {
    factors.push_back(v.size());
  }
}

int32_t main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  int eid = 0;
  ed.resize(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ed[a].emplace_back(b, eid);
    ed[b].emplace_back(a, eid++);
    edges.emplace_back(a, b);
  }

  bicomps(myfunc);

  // cout << "There are " << factors.size() << endl;

  int g = factors[0];
  for (int f : factors) {
      g = __gcd(g, f);
  }
  for (int i = 1; i <= g; i++) {
    if (g % i == 0) {
      cout << i << " ";
    }
  }
}