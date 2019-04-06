#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;
vector<pii> edges;

int color[MAXN];
vector<int> adj[MAXN];

void dfs(int pos) {
    for (int i : adj[pos]) {
        if (color[i]) {
            if (color[i] == color[pos]) {
                cout << "NO";
                exit(0);
            }
        } else {
            color[i] = color[pos] * -1;
            dfs(i);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for (int a = 0; a < M; a++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int a = 1; a <= N; a++) {
        if (color[a] == 0) {
            color[a] = 1;
            dfs(a);
        }
    }

    cout << "YES\n";
    for (pii p : edges) {
        cout << (color[p.first] == 1);
    }
}
