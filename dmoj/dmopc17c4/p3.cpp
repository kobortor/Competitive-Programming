#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
vector<pll> adj[MAXN];

void addb(pll &p, ll x){
    //cout << "Added " << x << endl;
    if(x > p.first){
        p.second = p.first;
        p.first = x;
    } else if (x > p.second){
        p.second = x;
    }
    //cout << p.first << ", " << p.second << endl;
}

ll dp[MAXN][2];
pll best;

void dfs(int pos, int par){
    pll branches = pll(0, -1e15);

    for(pll p : adj[pos]){
        if(p.first == par){
            continue;
        }
        dfs(p.first, pos);

        addb(best, branches.first + dp[p.first][0] + p.second);
        addb(best, branches.second + dp[p.first][0] + p.second);
        addb(best, branches.first + dp[p.first][1] + p.second);
        addb(best, branches.second + dp[p.first][1] + p.second);

        addb(branches, dp[p.first][0] + p.second);
        addb(branches, dp[p.first][1] + p.second);
    }

    dp[pos][0] = branches.first;
    dp[pos][1] = branches.second;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a < N; a++){
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(pll(v, c));
        adj[v].push_back(pll(u, c));
    }

    dfs(1, -1);
    cout << best.second << endl;
}
