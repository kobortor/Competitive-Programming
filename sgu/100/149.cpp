#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10005;

vector<pii> adj[MAXN];
int deepest[MAXN][2];
int ans[MAXN];

void dfs1 (int pos) {
    for (pii p : adj[pos]) {
        dfs1(p.first);

        int newv = deepest[p.first][0] + p.second;
        if (newv > deepest[pos][0]) {
            deepest[pos][1] = deepest[pos][0];
            deepest[pos][0] = newv;
        } else if (newv > deepest[pos][1]) {
            deepest[pos][1] = newv;
        }
    }
}

void dfs2 (int pos, int abv) {
    ans[pos] = max(deepest[pos][0], abv);

    for (pii p : adj[pos]) {
        if (deepest[p.first][0] + p.second == deepest[pos][0]) {
            dfs2 (p.first, max(deepest[pos][1], abv) + p.second);
        } else {
            dfs2 (p.first, max(deepest[pos][0], abv) + p.second);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    for (int a = 2; a <= N; a++) {
        int par, wt;
        cin >> par >> wt;
        adj[par].push_back({a, wt});
    }

    dfs1 (1);
    dfs2 (1, 0);

    for (int a = 1; a <= N; a++) {
        cout << ans[a] << "\n";
    }
}
