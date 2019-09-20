#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
ll nums[MAXN];

int dist[MAXN];
vector<int> adj[MAXN];

void bfs (int src) {
    memset(dist, 0x3f, sizeof dist);

    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
        int fr = q.front();
        q.pop();

        for (int i : adj[fr]) {
            if (dist[i] > dist[fr] + 1) {
                dist[i] = dist[fr] + 1;
                q.push(i);
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int a = 1; a <= N; a++) cin >> nums[a];

    vector<pii> edges;
    for (int a = 0; a < 63; a++) {
        vector<int> bits;
        for (int i = 1; i <= N; i++) {
            if (nums[i] & (1ll << a)) {
                bits.push_back(i);
            }
        }

        if ((int)bits.size() > 2) {
            cout << 3;
            return 0;
        } else if ((int)bits.size() == 2) {
            edges.push_back({bits[0], bits[1]});
        }
    }

    int ans = INT_MAX;
    for (pii p : edges) {
        if (find(allof(adj[p.first]), p.second) != adj[p.first].end()) {
            continue;
        }
        bfs(p.first);

        ans = min(ans, dist[p.second] + 1);

        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }

    if (ans < 10000) {
        cout << ans;
    } else {
        cout << -1;
    }
}
