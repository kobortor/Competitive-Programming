#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 16006;

int n;
int sz[MAXN];
vector<int> adj[MAXN];
vector<pii> nodes;

void dfs (int pos, int par) {
    sz[pos] = 1;

    int max_child = 0;
    for (int i : adj[pos]) {
        if (i == par) continue;
        
        dfs(i, pos);
        sz[pos] += sz[i];
        max_child = max(max_child, sz[i]);
    }

    nodes.push_back({max(max_child, n - sz[pos]), pos});
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int a = 1; a <= n - 1; a++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs (1, -1);

    sort(allof(nodes));
    int cnt = 1;
    while (cnt < (int)nodes.size() && nodes[cnt].first == nodes[0].first) {
        cnt++;
    }

    cout << nodes[0].first << " " << cnt << endl;
    for (int a = 0; a < cnt; a++) {
        cout << nodes[a].second << " ";
    }
}
