#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 16005;

int N;
int val[MAXN];
int best[MAXN];
vector<int> adj[MAXN];

void dfs (int pos, int par) {
    best[pos] = val[pos];
    for (int i : adj[pos]) {
        if (i == par) continue;

        dfs (i, pos);
        best[pos] += max(best[i], 0);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int a = 1; a <= N; a++) {
        cin >> val[a];
    }

    for (int a = 1; a <= N - 1; a++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs (1, -1);

    cout << *max_element(best + 1, best + N + 1);
}
