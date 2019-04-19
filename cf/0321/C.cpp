#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
vector<int> adj[MAXN];
bool blocked[MAXN];
char ans[MAXN];
int sz[MAXN];

void sz_dfs(int pos, int par) {
    if (blocked[pos]) {
        sz[pos] = 0;
        return;
    }

    sz[pos] = 1;
    for (int i : adj[pos]) {
        if (i == par) continue;
        if (blocked[i]) continue;

        sz_dfs(i, pos);
        sz[pos] += sz[i];
    }
}

pii find_centroid(int pos, int par, int abv) {
    int tot = abv + sz[pos];
    pii wt = {abv, pos};
    for (int i : adj[pos]) {
        if (i == par) continue;
        if (blocked[i]) continue;

        wt.first = max(wt.first, sz[i]);
    }

    for (int i : adj[pos]) {
        if (i == par) continue;
        if (blocked[i]) continue;

        wt = min(wt, find_centroid(i, pos, tot - sz[i]));
    }
    return wt;
}

void centroid(int src, char ch) {
    sz_dfs(src, -1);
    int center = find_centroid(src, -1, 0).second;

    ans[center] = ch;
    blocked[center] = true;
    for (int i : adj[center]) {
        if (!blocked[i]) {
            centroid(i, ch + 1);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int a = 1; a < N; a++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    centroid(1, 'A');
    for (int a = 1; a <= N; a++) {
        cout << ans[a] << " ";
    }
}
