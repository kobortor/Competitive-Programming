#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N;

vector<int> adj[MAXN];
int dsu[MAXN];
int sz[MAXN];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

bool vis[MAXN];

vector<pii> sorted;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        sorted.push_back({x, a});
    }

    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(allof(sorted));

    ll ans = 0;
    for(pii p : sorted) {
        sz[p.second] = 1;
        dsu[p.second] = p.second;

        ll accum = 1;
        for(int i : adj[p.second]){
            if(sz[i]){
                int fu = find(i);
                ans += accum * sz[fu] * p.first;
                accum += sz[fu];

                dsu[fu] = p.second;
            }
        }
        sz[p.second] = accum;
    }

    memset(sz, 0, sizeof sz);

    reverse(allof(sorted));
    for(pii p : sorted) {
        sz[p.second] = 1;
        dsu[p.second] = p.second;

        ll accum = 1;
        for(int i : adj[p.second]){
            if(sz[i]){
                int fu = find(i);
                ans -= accum * sz[fu] * p.first;
                accum += sz[fu];

                dsu[fu] = p.second;
            }
        }
        sz[p.second] = accum;
    }
    cout << ans;
}
