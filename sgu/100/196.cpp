#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// For each pair of edges, count the number of intersections they have

const int MAXN = 10005;
ll adj[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u]++;
        adj[v]++;
    }

    ll ans = 0;
    for (int a = 1; a <= N; a++) {
        ans += adj[a] * adj[a];
    }

    cout << ans;
}
