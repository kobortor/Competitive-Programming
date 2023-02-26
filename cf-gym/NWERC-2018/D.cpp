#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

ll N, M, A, B;

struct Edge {
    ll u, v, c;
};

vector<Edge> edges;

ll dist[MAXN];
vector<pll> reverse_adj[MAXN];

bool good(ll wait_time) {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> A >> B; 
    while (M--) {
        Edge e;
        cin >> e.u >> e.v >> e.c;
        edges.push_back(e);
    }

    ll lo = 0, hi = 3e12;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (good(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << endl;
}
