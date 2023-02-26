#include "bits/stdc++.h"

using namespace std;

#define ll long long
const ll INF = 1e17;

struct Dinic
{
  
  struct Edge
  {
    int to, rev;
    ll c, oc;
    ll flow() { return max(oc - c, 0LL); }
  };

  vector<int> lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}

  void add_edge(int a, int b, ll c, ll rcap = 0) {
    adj[a].push_back({b, (int)adj[b].size(), c, c});
    adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
  }

  ll dfs(int v, int t, ll f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < adj[v].size(); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1) {
        if (ll p = dfs(e.to, t, min(f, e.c))) {
          e.c -= p;
          adj[e.to][e.rev].c += p;
          return p;
        }
      }
    }
    return 0;
  }

  ll calc(int s, int t) {
    ll flow = 0; q[0] = s;

    for (int L = 0; L <= 30; L++) { 
      do {

        lvl = ptr = vector<int>(q.size());
        int qi = 0, qe = lvl[s] = 1;
        while (qi < qe && !lvl[t]) {
          int v = q[qi++];
          for (Edge e : adj[v]) {
            if (!lvl[e.to] && e.c >> (30 - L)) {
              q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
          }
        }
        while (ll p = dfs(s, t, INF)) flow += p;

      } while(lvl[t]);

    }

    return flow;
  }

};

int main() {

  int n, m, p;
  cin >> n >> m >> p;

  vector<vector<int>> like(n);
  vector<int> which_category(m, 0);
  vector<ll> category_limit = {INF};

  for (int i = 0; i < n; i++) {
    int k; cin >> k;
    while (k--) {
      int x; cin >> x;
      x--;
      like[i].push_back(x);
    }
  }

  for (int i = 1; i <= p; i++) {
    int k; cin >> k;
    while (k--) {
      int x; cin >> x;
      x--;
      which_category[x] = i;
    }
    ll foo; cin >> foo;
    category_limit.push_back(foo);
  }

  int nodes = 1 + category_limit.size() + which_category.size() + like.size() + 1;
  Dinic helper(nodes);

  // to categories
  for (int i = 0; i < category_limit.size(); i++) {
    helper.add_edge(0, i + 1, category_limit[i]);
  }

  // categories to toys
  for (int i = 0; i < which_category.size(); i++) {
    helper.add_edge(which_category[i] + 1, 1 + category_limit.size() + i, 1);
  }
  
  // toys to children
  for (int i = 0; i < like.size(); i++) {
    for (int j : like[i]) {
      int ov = 1 + category_limit.size();
      helper.add_edge(ov + j, ov + which_category.size() + i, 1);
    }
  }

  // children to sink
  for (int i = 0; i < like.size(); i++) {
    helper.add_edge(nodes - 1 - i - 1, nodes - 1, 1);
  }

  cout << helper.calc(0, nodes - 1) << "\n";

}