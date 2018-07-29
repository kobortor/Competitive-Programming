#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
vector<pii> adj[MAXN];

bitset<MAXN> vis;
int blw[MAXN][2];

int dfs1(int pos, int par){
    int res = 0;
    vis[pos] = true;

    for(pii p : adj[pos]){
        if(p.first == par){
            continue;
        }
        res = max(res, dfs1(p.first, pos));
        int len = blw[p.first][0] + p.second;
        if(len > blw[pos][0]){
            blw[pos][1] = blw[pos][0];
            blw[pos][0] = len;
        } else if (len > blw[pos][1]){
            blw[pos][1] = len;
        }
    }

    return max(res, blw[pos][0] + blw[pos][1]);
}

int dfs2(int pos, int par, int abv){
    int best = max(abv, blw[pos][0]);
    for(pii p : adj[pos]){
        if(p.first == par){
            continue;
        }
        
        if(blw[p.first][0] + p.second == blw[pos][0]){
            best = min(best, dfs2(p.first, pos, max(blw[pos][1], abv) + p.second));
        } else {
            best = min(best, dfs2(p.first, pos, max(blw[pos][0], abv) + p.second));
        }
    }

    return best;
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    int ans = 0;
    int best1 = -1, best2 = -1, best3 = -1;
    for(int a = 0; a < M; a++){
        adj[A[a]].emplace_back(B[a], T[a]);
        adj[B[a]].emplace_back(A[a], T[a]);
    }
    for(int a = 0; a < N; a++){
        if(!vis[a]){
            ans = max(ans, dfs1(a, -1));
            int res = dfs2(a, -1, 0);
            if(res > best1){
                best3 = best2;
                best2 = best1;
                best1 = res;
            } else if (res > best2){
                best3 = best2;
                best2 = res;
            } else if (res > best3){
                best3 = res;
            }
        }
    }

    if(best2 != -1){
        ans = max(ans, best1 + best2 + L);
    }

    if(best3 != -1){
        ans = max(ans, best2 + best3 + L * 2);
    }
    return ans;
}
