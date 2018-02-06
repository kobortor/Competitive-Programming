#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 51;

double adj[MAXN][MAXN];
pair<double, double> coord[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    while(1){
        int N, M;
        cin >> N >> M;
        if(!N && !M){
            break;
        }
        for(int a = 1; a <= N; a++){
            cin >> coord[a].first;
            cin >> coord[a].second;

            for(int b = 1; b <= N; b++){
                adj[a][b] = 1e15;
            }
            adj[a][a] = 0;
        }
        while(M--){
            int u, v;
            cin >> u >> v;
            double dist = hypot(coord[u].first - coord[v].first, coord[u].second - coord[v].second);
            adj[u][v] = dist;
            adj[v][u] = dist;
        }
        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++){
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        pii best_idx;
        double best = 0;
        for(int a = 1; a <= N; a++){
            for(int b = 1; b <= N; b++){
                double dist = hypot(coord[a].first - coord[b].first, coord[a].second - coord[b].second);
                double saving = 0;
                for(int i = 1; i <= N; i++){
                    for(int j = 1; j <= N; j++){
                        double newcost = min(adj[i][a] + adj[b][j], adj[i][b] + adj[a][j]) + dist;
                        saving += max(0.0, adj[i][j] - newcost);
                    }
                }
                if(saving > best){
                    best = saving;
                    best_idx = pii(a, b);
                }
            }
        }
        if(best <= 1){
            cout << "No road required\n";
        } else {
            cout << best_idx.first << " " << best_idx.second << "\n";
        }
    }
}
