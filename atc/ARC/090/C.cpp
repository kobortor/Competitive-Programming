#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const ll mod = 1e9 + 7;

int N, M;
int S, T;

ll best[2][MAXN];
vector<pll> adj[MAXN];
vector<int> pth[2][MAXN];

void dijkstra(int tp){
    memset(best[tp], 0x3f, sizeof best[tp]);
    best[tp][tp == 0 ? S : T] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, tp == 0 ? S : T});
    while(!pq.empty()){
        pll top = pq.top();
        pq.pop();

        for(pll p : adj[top.second]){
            if(top.first + p.second < best[tp][p.first]){
                best[tp][p.first] = top.first + p.second;
                pq.push({best[tp][p.first], p.first});
            }
        }
    }
}

int incoming[2][MAXN];
ll pcnt[2][MAXN];

void count_path(int tp){
    pcnt[tp][tp == 0 ? S : T] = 1;
    queue<int> q;
    q.push(tp == 0 ? S : T);
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        for(int i : pth[tp][fr]){
            pcnt[tp][i] += pcnt[tp][fr];
            pcnt[tp][i] %= mod;

            incoming[tp][i]--;
            if(!incoming[tp][i]){
                q.push(i);
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    cin >> S >> T;
    for(int a = 0; a < M; a++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(pll(v, c));
        adj[v].push_back(pll(u, c));
    }

    dijkstra(0);
    dijkstra(1);

    for(int a = 1; a <= N; a++){
        if(best[0][a] + best[1][a] != best[0][T]){
            continue;
        }
        for(pll p : adj[a]){
            if(best[0][a] + p.second == best[0][p.first] && best[0][p.first] + best[1][p.first] == best[0][T]){
                pth[0][a].push_back(p.first);

                incoming[0][p.first]++;
            }
            if(best[1][a] + p.second == best[1][p.first] && best[0][p.first] + best[1][p.first] == best[0][T]){
                pth[1][a].push_back(p.first);

                incoming[1][p.first]++;
            }
        }
    }
    count_path(0);
    count_path(1);

    ll ans = pcnt[0][T] * pcnt[1][S] % mod;
    for(int a = 1; a <= N; a++){
        if(best[0][a] == best[1][a]){
            ll val = pcnt[0][a] * pcnt[1][a] % mod;
            ans -= val * val;
            ans %= mod;
        }
        for(int i : pth[0][a]){
            if(best[0][a] * 2 < best[0][T] && best[0][T] < best[0][i] * 2){
                ll val = pcnt[0][a] * pcnt[1][i] % mod;
                ans -= val * val % mod;
                ans %= mod;
            }
        }
    }
    ans %= mod;
    if(ans < 0){
        ans += mod;
    }
    cout << ans % mod;
}
