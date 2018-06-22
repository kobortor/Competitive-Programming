#include <bits/stdc++.h>

const int MAXN = 2e5 + 5;

using namespace std;

typedef pair<int, int> pii;

int N, K;

bool blocked[MAXN];
vector<pii> adj[MAXN];

int sz[MAXN];

void sz_dfs(int pos, int par){
    sz[pos] = 1;
    for(pii p : adj[pos]){
        if(p.first == par || blocked[p.first]){
            continue;
        }

        sz_dfs(p.first, pos);
        sz[pos] += sz[p.first];
    }
}

pii centroid_dfs(int pos, int par, int tot){
    pii best = pii(tot - sz[pos], pos);
    for(pii p : adj[pos]){
        if(p.first == par || blocked[p.first]){
            continue;
        }
        best.first = max(best.first, sz[p.first]);
    }

    for(pii p : adj[pos]){
        if(p.first == par || blocked[p.first]){
            continue;
        }
        best = min(best, centroid_dfs(p.first, pos, tot));
    }

    return best;
}

void solve_dfs(int pos, int par, int len, int steps, unordered_map<int, int> &mp){
    if(len > K){
        return;
    }

    if(!mp.count(len)){
        mp[len] = 1e9;
    }

    mp[len] = min(mp[len], steps);

    for(pii p : adj[pos]){
        if(p.first == par || blocked[p.first]){
            continue;
        }

        solve_dfs(p.first, pos, len + p.second, steps + 1, mp);
    }
}

int main_dfs(int pos){
    sz_dfs(pos, -1);
    int centroid = centroid_dfs(pos, -1, sz[pos]).second;

    blocked[centroid] = true;

    unordered_map<int, int> avail;
    avail[0] = 0;

    int ans = 1e9;

    for(pii p : adj[centroid]){
        if(blocked[p.first]){
            continue;
        }

        unordered_map<int, int> mp;
        solve_dfs(p.first, centroid, p.second, 1, mp);

        for(pii p2 : mp){
            if(avail.count(K - p2.first)){
                ans = min(ans, avail[K - p2.first] + p2.second);
            }
        }

        for(pii p2 : mp){
            if(!avail.count(p2.first)){
                avail[p2.first] = 1e9;
            }

            avail[p2.first] = min(avail[p2.first], p2.second);
        }
    }

    for(pii p : adj[centroid]){
        if(!blocked[p.first]){
            ans = min(ans, main_dfs(p.first));
        }
    }
    
    return ans;
}

int best_path(int _N, int _K, int _H[][2], int _L[]){
    N = _N;
    K = _K;

    for(int a = 0; a < N - 1; a++){
        adj[_H[a][0]].push_back({_H[a][1], _L[a]});
        adj[_H[a][1]].push_back({_H[a][0], _L[a]});
    }

    int res = main_dfs(0);

    if(res == 1e9){
        return -1;
    } else {
        return res;
    }
}
