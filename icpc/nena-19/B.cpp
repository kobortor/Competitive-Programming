#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

vector<int> resources[MAXN];
vector<int> adj[MAXN];

int col[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        int x;
        while (true) {
            cin >> x;
            if (x == 0) break;
            resources[x].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        int u = resources[i][0];
        int v = resources[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= m; i++) {
        if (col[i] == 0) {
            queue<int> q;
            q.push(i);
            col[i] = 1;
            while (!q.empty()) {
                int fr = q.front();
                q.pop();
                for (int v : adj[fr]) {
                    if (col[v] == col[fr]) {
                        cout << "NO\n";
                        return 0;
                    } else if (col[v] == 0) {
                        col[v] = -col[fr];
                        q.push(v);
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
}
