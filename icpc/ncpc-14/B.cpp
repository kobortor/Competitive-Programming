#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int block[MAXN];
vector<int> adj[MAXN];

int k, n;

void change(int pos, int delta) {
    block[pos] += delta;
    for (int i : adj[pos]) {
        block[i] += delta;
    }
}

void dfs(int pos, int rem) {
    if (rem == 0) {
        cout << "possible\n";
        exit(0);
    }
    if (pos > n) return;

    if (!block[pos]) {
        change(pos, +1);
        dfs(pos + 1, rem - 1);
        change(pos, -1);

        if (rem >= 2 && adj[pos].size() > 1) {
            for (int i : adj[pos]) {
                if (block[i]) continue;

                change(i, +1);

                for (int j : adj[pos]) {
                    if (i < j && !block[j]) {
                        change(j, +1);
                        dfs(pos + 1, rem - 2);
                        change(j, -1);
                    }
                }
                change(i, -1);
            }
        } else {
            dfs(pos + 1, rem);
        }
    } else {
        dfs(pos + 1, rem);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> k >> n;
    if (n > 5 * k) {
        cout << "possible\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int di;
        cin >> di;
        while (di--) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    dfs(1, k);

    cout << "impossible\n";
}
