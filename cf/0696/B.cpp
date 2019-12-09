#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];

double sz[MAXN];
double ans[MAXN];

void dfs1 (int pos) {
    sz[pos] = 1;
    for (int i : adj[pos]) {
        dfs1(i);
        sz[pos] += sz[i];
    }
}

void dfs2 (int pos, double expect_abv) {
    // 0.5 * (1 + (sz[i] - 1))
    // = 0.5 * sz[i]
    //
    // sum sz[i] = sz[pos] - 1
    // sum 0.5 sz[i] = 0.5 * (sz[pos] - 1)

    ans[pos] = expect_abv;

    for (int i : adj[pos]) {
        dfs2(i, expect_abv + 0.5 * (sz[pos] - 1) - 0.5 * sz[i] + 1);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int a = 2; a <= n; a++) {
        int par;
        cin >> par;
        adj[par].push_back(a);
    }

    dfs1(1);
    dfs2(1, 1);

    for (int a = 1; a <= n; a++) {
        cout << fixed << setprecision(8) << ans[a] << " ";
    }
}
