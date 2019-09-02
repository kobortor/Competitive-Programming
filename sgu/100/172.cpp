#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 202;

int n, m;

int col[MAXN];
vector<int> adj[MAXN];

void dfs (int pos) {
    for (int i : adj[pos]) {
        if (col[i] == 0) {
            col[i] = -col[pos];
            dfs(i);
        } else if (col[i] == col[pos]) {
            cout << "no";
            exit(0);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int a = 1; a <= n; a++) {
        if (col[a] == 0) {
            col[a] = 1;
            dfs(a);
        }
    }

    cout << "yes\n";
    cout << count(col, col + MAXN, 1) << "\n";
    for (int a = 1; a <= n; a++) {
        if (col[a] == 1) {
            cout << a << " ";
        }
    }
}
