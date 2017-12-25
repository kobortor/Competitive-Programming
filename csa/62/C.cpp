#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M, Q;
vector<int> adj[MAXN];
vector<pii> bridges;

int cnt = 1;
int disc[MAXN];
int low[MAXN];
void tarjan(int pos, int par){
    disc[pos] = low[pos] = cnt++;
    for (int i : adj[pos]) {
        if (i == par) {
            continue;
        }
        if (disc[i] == 0) {
            tarjan(i, pos);
            low[pos] = min(low[pos], low[i]);
            if (low[i] == disc[i]) {
                bridges.push_back({i, pos});
            }
        } else {
            low[pos] = min(low[pos], disc[i]);
        }
    }
}

int dsu[MAXN];
int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q;
    for(int a = 1; a <= N; a++){
        dsu[a] = a;
    }

    while(M--){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    tarjan(1, -1);
    for(pii p : bridges){
        int fx = find(p.first);
        int fy = find(p.second);

        if(fx != fy){
            dsu[fx] = fy;
        }
    }

    while(Q--){
        int x, y;
        cin >> x >> y;
        cout << (find(x) == find(y)) << "\n";
    }
}