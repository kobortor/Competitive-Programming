#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

int N, M;

vector<pii> adj[MAXN];
ll dist[2][MAXN];
ll blw[2][MAXN][2];
int sz[MAXN];

void init_dfs(int pos, int par, int tp){
    for(pii p : adj[pos]){
        if(p.first == par){
            continue;
        }
        dist[tp][p.first] = dist[tp][pos] + p.second;
        init_dfs(p.first, pos, tp);
    }
}

void prep_dfs(int pos, int par){
    sz[pos] = 1;
    for(pii p : adj[pos]){
        if(p.first == par){
            continue;
        }

        prep_dfs(p.first, pos);
        sz[pos] += sz[p.first];

        for(int tp = 0; tp <= 1; tp++){
            ll tmp = max(blw[tp][p.first][0], dist[tp][p.first]);
            if(tmp > blw[tp][pos][0]){
                blw[tp][pos][1] = blw[tp][pos][0];
                blw[tp][pos][0] = tmp;
            } else if (tmp > blw[tp][pos][1]){
                blw[tp][pos][1] = tmp;
            }
        }
    }
}

ll ans = 0;

int extra1 = 0;
int extraN = 0;

bool solve_dfs(int pos, int par, ll abv){
    bool found = false;
    if(pos == N){
        found = true;
    }

    for(pii p : adj[pos]){
        if(p.first == par){
            continue;
        }

        ll newabv;
        if(blw[0][pos][0] == max(blw[0][p.first][0], dist[0][p.first])){
            newabv = max(abv, blw[0][pos][1]);
        } else {
            newabv = max(abv, blw[0][pos][0]);
        }

        if(solve_dfs(p.first, pos, max(newabv, dist[0][pos]))){
            found = true;
            ans = max(ans, newabv + max(dist[1][p.first], blw[1][p.first][0]));
        } else if (pos == 1){
            extra1 += sz[p.first];
        }

        if(pos == N){
            extraN += sz[p.first];
        }
    }

    if(found){
        ll added = blw[1][pos][0] == dist[1][pos] ? blw[1][pos][1] : blw[1][pos][0];
        ans = max(ans, abv + added);
        return true;
    } else {
        return false;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(blw, 0xaf, sizeof blw);

    cin >> N >> M;
    for(int a = 0; a < N - 1; a++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    init_dfs(1, -1, 0);
    init_dfs(N, -1, 1);

    prep_dfs(1, -1);

    solve_dfs(1, -1, -1e15);

    if(extra1 > 1 || extraN > 1){
        ans = 1e15;
    }

    while(M--){
        ll x;
        cin >> x;
        cout << min(dist[0][N], x + ans) << "\n";
    }
}
