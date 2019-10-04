#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

set<int> adj[MAXN];
int color[MAXN];

void dfs (int pos) {
    if (adj[pos].empty()) return;

    int colored = -1;
    for (int i : adj[pos]) {
        if (color[i] != 0) {
            colored = i;
            break;
        }
    }

    // since we are the only one without a neighbor, we must be 1
    if (colored == -1) {
        colored = *adj[pos].begin();
        color[colored] = 2;
    }

    vector<int> tovis;
    for (int i : adj[pos]) {
        if (color[i] == 0) {
            tovis.push_back(i);
            if (adj[colored].count(i)) {
                // they must be different colors!
                color[i] = 1 + 2 + 3 - color[colored] - color[pos];
                if (color[i] < 1 || color[i] > 3) {
                    cout << -1;
                    exit(0);
                }
            } else {
                color[i] = color[colored];
            }
        }
    }

    for (int i : tovis) {
        dfs(i);
    }
}

vector<int> groups[4];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<pii> edges;
    for (int a = 0; a < M; a++) {
        int ai, bi;
        cin >> ai >> bi;
        adj[ai].insert(bi);
        adj[bi].insert(ai);

        edges.push_back({ai, bi});
    }

    for (int a = 1; a <= N; a++) {
        if (color[a] == 0) {
            if (groups[1].empty()) {
                color[a] = 1;
            } else if (groups[2].empty()) {
                color[a] = 2;
            } else if (groups[3].empty()) {
                color[a] = 3;
            } else {
                color[a] = 1;
            }
            dfs(a);
        }
        groups[color[a]].push_back(a);
    }

    if (groups[1].empty() || groups[2].empty() || groups[3].empty()) {
        cout << -1;
        return 0;
    }

    ll edges_req = 0;
    edges_req += (ll)groups[1].size() * (ll)groups[2].size();
    edges_req += (ll)groups[1].size() * (ll)groups[3].size();
    edges_req += (ll)groups[2].size() * (ll)groups[3].size();

    if (edges_req != M) {
        cout << -1;
        return 0;
    }

    for (pii p : edges) {
        if (color[p.first] == color[p.second]) {
            cout << -1;
            return 0;
        }
    }

    for (int a = 1; a <= N; a++) {
        cout << color[a] << " ";
    }
}
