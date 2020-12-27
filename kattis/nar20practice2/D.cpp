#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int n, m;

vector<pii> adj[MAXN];

int dist[MAXN];
int sign[MAXN];

void dfs1() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, 1));

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    memset(sign, -1, sizeof sign);

    while (!pq.empty()) {
        auto [d, pos] = pq.top();
        pq.pop();

        for (pii p : adj[pos]) {
            if (d + p.second < dist[p.first]) {
                dist[p.first] = d + p.second;
                sign[p.first] = pos;
                pq.push(pii(dist[p.first], p.first));
            }
        }
    }
}

int par[MAXN];
void dfs2() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, 0));

    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;

    while (!pq.empty()) {
        auto [d, pos] = pq.top();
        pq.pop();

        for (pii p : adj[pos]) {
            if (p.first == sign[pos]) {
                continue;
            }
            if (d + p.second < dist[p.first]) {
                dist[p.first] = d + p.second;
                par[p.first] = pos;
                pq.push(pii(dist[p.first], p.first));
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;

    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(pii(v, c));
        adj[v].push_back(pii(u, c));
    }

    dfs1();
    dfs2();
    
    if (dist[1] == 0x3f3f3f3f) {
        cout << "impossible";
    } else {
        vector<int> path;
        path.push_back(1);

        int pos = 1;
        while (pos != 0) {
            pos = par[pos];
            path.push_back(pos);
        }

        reverse(allof(path));
        cout << path.size() << " ";
        for (int i : path) {
            cout << i << " ";
        }
    }
}
