#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;
set<int> adj[MAXN];

bool erased[MAXN];

bool vis[MAXN];
void dfs(int pos, vector<int> &nodes, vector<pii> &edges) {
    if (vis[pos]) return;
    // cout << "Add " << pos << endl;;

    vis[pos] = true;
    nodes.push_back(pos);
    for (int nxt : adj[pos]) {
        edges.push_back({pos, nxt});
        // edges.push_back({nxt, pos});
        dfs(nxt, nodes, edges);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<pii> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        edges.push_back({u, v});
    }

    vector<pii> answer;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        vector<int> nodes;
        vector<pii> edges;
        dfs(i, nodes, edges);

        // cout << i << endl;

        if (edges.size() == 2 * (nodes.size() - 1)) {
            // cout << "Found tree\n";
            // tree
            for (pii p : edges) {
                if (adj[p.first].size() == 1) {
                    answer.push_back(p);
                }
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int fr = q.front();
        q.pop();
        erased[fr] = true;

        vector<int> tmp_adj{allof(adj[fr])};
        for (int nxt : tmp_adj) {
            adj[nxt].erase(fr);
            adj[fr].erase(nxt);

            if (adj[nxt].size() == 1) {
                q.push(nxt);
            }
        }
    }

    for (pii p : edges) {
        if (erased[p.first] != erased[p.second]) {
            if (erased[p.first]) {
                swap(p.first, p.second);
            }
            answer.push_back(p);
            // cout << p.first << " " << p.second << "\n";
        }
    }
    sort(allof(answer));
    cout << answer.size() << "\n";
    for (pii p : answer) {
        cout << p.first << " " << p.second << "\n";
    }
}
