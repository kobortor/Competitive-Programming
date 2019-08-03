#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];

double dfs(int pos, int par){
    double ans = 0;
    int children = 0;
    for (int i : adj[pos]) {
        if (i == par) continue;

        ans += 1 + dfs(i, pos);
        children++;
    }
    if (children == 0) return 0.0;
    else return ans / children;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    for (int a = 0, u, v; a < n - 1; a++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << fixed << setprecision(10) << dfs(1, -1);
}
