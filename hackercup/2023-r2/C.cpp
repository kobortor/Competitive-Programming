#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e6 + 6;

vector<int> adj[MAXN];
vector<int> knowledge[MAXN];
unordered_map<string, int> namemap;
unordered_map<int, string> lookup;
unordered_set<int> bad;

// returns number of leaves
int dfs(int node, unordered_map<int, int> &total) {
    int n_leaves = 0;
    if (adj[node].empty()) {
        n_leaves++;
    }

    for (int i : adj[node]) {
        unordered_map<int, int> mp;
        int leaves = dfs(i, mp);
        n_leaves += leaves;
        if (mp.size() > total.size()) {
            swap(mp, total);
        }
        for (pii p : mp) {
            total[p.first] += p.second;
        }
    }

    for (int i : knowledge[node]) {
        total[i] = min(total[i] + (node != 0), n_leaves);
        if (total[i] < n_leaves) {
            // cout << "Reject " << lookup[i] << " at " << node << endl;
            bad.insert(i);
        }
    }
    return n_leaves;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";

        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            int par;
            cin >> par;
            adj[par].push_back(i);
        }

        for (int i = 1; i <= n; i++) {
            int cnt;
            cin >> cnt;
            while (cnt--) {
                string s;
                cin >> s;

                int id;
                if (namemap.count(s)) {
                    id = namemap[s];
                } else {
                    id = namemap.size();
                    lookup[id] = s;
                    // cout << s << " is " << id << endl;
                    namemap[s] = id;
                }

                knowledge[i].push_back(id);
            }
        }
        for (int i = 0 ; i < namemap.size(); i++) {
            knowledge[0].push_back(i);
        }
        adj[0].push_back(1);

        unordered_map<int, int> total;
        dfs(0, total);

        cout << namemap.size() - bad.size() << endl;

        bad.clear();
        namemap.clear();
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            knowledge[i].clear();
        }
    }

}