#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    set<string> languages;
    languages.insert("English");

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        languages.insert(s);
    }

    map<string, vector<pair<string, int>>> adj;

    for (int i = 0; i < m; i++) {
        string u, v;
        int c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    queue<string> q;
    map<string, int> dist;
    q.push("English");
    dist["English"] = 0;

    while (!q.empty()) {
        string front = q.front();
        q.pop();
        for (auto &[nxt, wt] : adj[front]) {
            if (dist.count(nxt) == 0) {
                dist[nxt] = dist[front] + 1;
                q.push(nxt);
            }
        }
    }

    for (string s : languages) {
        if (dist.count(s) == 0) {
            cout << "Impossible\n";
            return 0;
        }
    }

    vector<set<string>> layers(n + 2);
    for (auto [s, d] : dist) {
        layers[d].insert(s);
    }

    ll ans = 0;

    for (int i = 0; i + 1 < layers.size(); i++) {
        set<string> unseen = layers[i + 1];

        vector<pair<int, string>> edges;
        for (string s : layers[i]) {
            for (auto [s2, c] : adj[s]) {
                if (dist[s2] == i + 1) {
                    edges.push_back({c, s2});
                }
            }
        }

        sort(edges.begin(), edges.end());
        for (auto [c, s] : edges) {
            if (unseen.count(s)) {
                unseen.erase(s);
                ans += c;
            }
        }
    }

    cout << ans << "\n";
}