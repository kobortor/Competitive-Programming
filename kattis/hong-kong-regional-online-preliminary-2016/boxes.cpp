#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int jmp[MAXN][20];
int dep[MAXN];
int sz[MAXN];

void dfs(int pos) {
    for (int i = 0; i + 1 < 20; i++) {
        if (jmp[jmp[pos][i]][i] == -1) {
            break;
        } else {
            jmp[pos][i + 1] = jmp[jmp[pos][i]][i];
        }
    }
    sz[pos] = 1;

    for (int i : adj[pos]) {
        jmp[i][0] = pos;
        dep[i] = dep[pos] + 1;
        dfs(i);
        sz[pos] += sz[i];
    }
}

int jump_up(int pos, int k) {
    for (int i = 0; i < 20; i++) {
        if (k & (1 << i)) {
            pos = jmp[pos][i];
        }
    }

    return pos;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(jmp, -1, sizeof(jmp));

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int par;
        cin >> par;

        adj[par].push_back(i);
    }

    dfs(0);

    int Q;
    cin >> Q;
    while (Q--) {
        int m;
        cin >> m;

        vector<int> v(m);
        for (int &vi : v) {
            cin >> vi;
        }

        sort(allof(v), [&](int u, int v) { return dep[u] < dep[v]; });

        int ans = 0;

        for (int i = 0; i < (int)v.size(); i++) {
            bool included = false;
            for (int j = 0; j < i; j++) {
                int diff = dep[v[i]] - dep[v[j]];
                if (v[j] == jump_up(v[i], diff)) {
                    included = true;
                    break;
                }
            }

            if (!included) {
                ans += sz[v[i]];
            }
        }

        cout << ans << "\n";
    }
}
