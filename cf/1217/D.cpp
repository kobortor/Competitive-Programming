#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

vector<int> adj[MAXN];
int incoming[MAXN];
bool vis[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<pii> edges;
    while (M--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        incoming[v]++;

        edges.push_back({u, v});
    }

    queue<int> q;
    for (int a = 1; a <= N; a++) {
        if (!incoming[a]) {
            q.push(a);
        }
    }

    while (!q.empty()) {
        int fr = q.front();
        vis[fr] = true;
        q.pop();

        for (int i : adj[fr]) {
            if (!--incoming[i]) {
                q.push(i);
            }
        }
    }

    if (count(vis, vis + MAXN, true) == N) {
        cout << "1\n";
        for (int a = 0; a < (int)edges.size(); a++) {
            cout << "1 ";
        }
    } else {
        cout << "2\n";
        for (pii p : edges) {
            if (p.first < p.second) {
                cout << "1 ";
            } else {
                cout << "2 ";
            }
        }
    }
}
