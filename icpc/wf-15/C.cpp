#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

typedef vector<int> vi;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
const ll INF = numeric_limits<ll>::max() / 4;

struct MCMF {
  struct edge {
    int from, to, rev;
    ll cap, cost, flow;
  };
  int N;
  vector<vector<edge>> ed;
  vi seen;
  vector<ll> dist, pi;
  vector<edge*> par;

  MCMF(int N): N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

  void addEdge(int from, int to, ll cap, ll cost) {
    if (from == to) return;
    ed[from].push_back(edge{from, to, sz(ed[to]), cap, cost, 0});
    ed[to].push_back(edge{to, from, sz(ed[from])-1, 0, -cost, 0});
  }

  void path(int s) {
    fill(all(seen), 0);
    fill(all(dist), INF);
    dist[s] = 0;
    ll di;

    __gnu_pbds::priority_queue<pair<ll, int>> q;
    vector<decltype(q)::point_iterator> its(N);
    q.push({0, s});

    while (!q.empty()) {
      s = q.top().second; q.pop();
      seen[s] = 1; di = dist[s] + pi[s];
      for (edge& e : ed[s]) if (!seen[e.to]) {
        ll val = di - pi[e.to] + e.cost;
        if (e.cap - e.flow > 0 && val < dist[e.to]) {
          dist[e.to] = val;
          par[e.to] = &e;
          if (its[e.to] == q.end()) {
            its[e.to] = q.push({-dist[e.to], e.to});
          } else {
            q.modify(its[e.to], {-dist[e.to], e.to});
          }
        }
      }
    }
    for (int i = 0; i < N; i++) {
        pi[i] = min(pi[i] + dist[i], INF);
    }
  }

  pll maxflow(int s, int t) {
    ll totflow = 0, totcost = 0;
    while (path(s), seen[t]) {
      ll fl = INF;
      for (edge *x = par[t]; x; x = par[x->from]) {
        fl = min(fl, x->cap - x->flow);
      }
      totflow += fl;
      for (edge* x = par[t]; x; x = par[x->from]) {
        x->flow += fl;
        ed[x->to][x->rev].flow -= fl;
      }
    }
    for( int i = 0; i < N; i++) {
      for (edge &e : ed[i]) totcost += e.cost * e.flow;
    }
    return {totflow, totcost / 2};
  }

  void setpi(int s) {
    fill(all(pi), INF);
    pi[s] = 0;
    int it = N, ch = 1; ll v;
    while (ch-- && it--) {
      for (int i = 0; i < N; i++) {
        if (pi[i] != INF) {
          for (edge &e : ed[i]) {
            if (e.cap) {
              if ((v = pi[i] + e.cost) < pi[e.to]) {
                pi[e.to] = v, ch = 1;
              }
            }
          }
        }
      }
    }
    assert(it >= 0);
  }
};

const int MAXN = 105;

int n, k;
ll cost[MAXN][MAXN];

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  cin >> n >> k;

  int START = 0;
  int END = 2 * n + 2;

  MCMF mcmf(2 * n + 3);
  mcmf.addEdge(0, 1, k, 0);
  mcmf.addEdge(1, 2 * n + 2, k, 0);
  for (int i = 1; i <= n; i++) {
    mcmf.addEdge(2 * i, 2 * i + 1, 1, -1e9);
    mcmf.addEdge(2 * i + 1, 2 * n + 2, 1, 0);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> cost[i][j];
      // cout << i << " to " << j << " with " << cost[i][j] << endl;
      mcmf.addEdge(2 * i + 1, 2 * j, 1, cost[i][j]);
    }
  }

  mcmf.setpi(START);
  pll p = mcmf.maxflow(START, END);
  ll ans = p.second + n * ll(1e9);
  cout << ans << endl;
}