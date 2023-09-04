#include<bits/stdc++.h>

// Created by kobortor On 16:38:49 on 26-05-2023

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

vector<pii> cuts;
map<pii, int> edges;

vector<int> leaves[MAXN];
set<int> adj[MAXN];
bool used[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cuts.clear();
        edges.clear();
        for (int i = 1; i <= n; i++) {
            used[i] = false;
            leaves[i].clear();
            adj[i].clear();
        }

        for (int i = 1, u, v; i <= n - 1; i++) {
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);

            edges[pii(u, v)] = i;
            edges[pii(v, u)] = i;
        }

        if (n % 3 != 0) {
            cout << "-1\n";
            continue;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
            if (adj[i].size() == 1) {
                leaves[*adj[i].begin()].push_back(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            vector<int> in_branch;
            if (leaves[i].size() == 1 && adj[i].size() == 2) {
                in_branch = vector<int>(allof(adj[i]));
            } else if (leaves[i].size() == 2) {
                in_branch = leaves[i];
            } else {
                continue;
            }
            in_branch.push_back(i);

            bool good = true;
            for (int x : in_branch) {
                if (used[x]) {
                    good = false;
                } else {
                    used[x] = true;
                }
            }
            if (!good) continue;

            for (int u : in_branch) {
                for (int v : adj[u]) {
                    if (v == in_branch[0]) continue;
                    if (v == in_branch[1]) continue;
                    if (v == in_branch[2]) continue;

                    cuts.push_back({u, v});

                    adj[v].erase(u);
                    if (adj[v].size() == 1) {
                        leaves[*adj[v].begin()].push_back(v);
                        q.push(*adj[v].begin());
                    }
                }
            }
        }

        if (((int)cuts.size() + 1) * 3 == n) {
            cout << cuts.size() << "\n";
            for (pii p : cuts) {
                cout << edges[p] << " ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
