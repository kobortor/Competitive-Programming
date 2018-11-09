#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M, K;
vector<pii> adj[MAXN];
ll mat[MAXN][MAXN];

void djikstra(int src){
    fill(mat[src], mat[src] + MAXN, 1e18);
    mat[src][src] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});
    
    while(!pq.empty()){
        pll top = pq.top();
        pq.pop();

        for(pii p : adj[top.second]){
            if(mat[src][p.first] > top.first + p.second){
                mat[src][p.first] = top.first + p.second;
                pq.push({mat[src][p.first], p.first});
            }
        }
    }
}

struct {
    ll s, u, t;
} orders [MAXN];
ll dp[MAXN];
bool check(ll tm){
    fill(dp, dp + MAXN, 1e18);

    dp[0] = 0;
    for(int a = 1; a <= K; a++){
        ll prvpos = 1;
        ll elapsed = 0;
        ll maxt = dp[a - 1];
        ll lateststart = 1e18;
        for(int b = a; b <= K; b++){
            elapsed += mat[prvpos][orders[b].u];
            maxt = max(maxt, orders[b].t);
            lateststart = min(lateststart, orders[b].s + tm - elapsed);
            prvpos = orders[b].u;

            if(lateststart < maxt){
                break;
            } else {
                dp[b] = min(dp[b], maxt + elapsed + mat[orders[b].u][1]);
            }
        }

        if(dp[a] == 1e18){
            return false;
        }
    }

    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    while(M--){
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    for(int a = 1; a <= N; a++){
        djikstra(a);
    }

    cin >> K;
    for(int a = 1; a <= K; a++){
        cin >> orders[a].s;
        cin >> orders[a].u;
        cin >> orders[a].t;
    }

    ll lo = 0, hi = 1e18;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(!check(mid)){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << endl;
}
