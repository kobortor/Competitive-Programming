#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

bool ban[MAXN];
bool req[MAXN];
int col[MAXN];

vector<int> adj[MAXN];

int n0, n1;
void dfs(int pos) {
    for (int i : adj[pos]) {
        if (col[i] == col[pos]) {
            cout << "impossible\n";
            exit(0);
        }
        if (col[i] == 0) {
            col[i] = -col[pos];
            if (col[i] == 1) {
                n1++;
            } else {
                n0++;
            }
            dfs(i);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v, t;
        cin >> u >> v >> t;
        if (t == 0) {
            ban[u] = ban[v] = true;
        } else if (t == 2) {
            req[u] = req[v] = true;
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ban[i] && col[i] == +1) {
            cout << "impossible\n";
            return 0;
        }
        if (req[i] && col[i] == -1) {
            cout << "impossible\n";
            return 0;
        }
        if (col[i] == 0) {
            if (ban[i]) {
                if (req[i]) {
                    cout << "impossible\n";
                    return 0;
                }

                col[i] = -1;
                n0 = 1;
                n1 = 0;
                dfs(i);
                ans += n1;
            } else if (req[i]) {
                col[i] = 1;
                n0 = 0;
                n1 = 1;
                dfs(i);
                ans += n1;
            }
        } 
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) {
            col[i] = 1;
            n0 = 0;
            n1 = 1;
            dfs(i);
            ans += min(n0, n1);
        }
    }
    cout << ans << endl;
}
