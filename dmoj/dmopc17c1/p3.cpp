#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
pii best[MAXN];
vector<pii> adj[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    while(M--){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    memset(best, 0x3f, sizeof best);

    priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;
    pq.push({{0, 0}, 1});
    best[1] = pii(0, 0);

    while(!pq.empty()){
        pii cost;
        int pos;
        tie(cost, pos) = pq.top();
        pq.pop();

        for(pii p : adj[pos]){
            if(pii(cost.first + p.second, cost.second + 1) < best[p.first]){
                best[p.first] = pii(cost.first + p.second, cost.second + 1);
                pq.push({best[p.first], p.first});
            }
        }
    }

    if(best[N].first > N){
        cout << -1;
    } else {
        cout << best[N].first << " " << best[N].second;
    }
}
