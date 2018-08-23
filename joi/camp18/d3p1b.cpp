#include "Boblib.h"
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1015;

static bool mat[MAXN][MAXN];
static int cnt[MAXN];
static vector<int> adj[MAXN];
static bool is_orig[MAXN];
static int real_idx[MAXN];

void Bob(int V, int U, int C[], int D[]){
    if(V == 1){
        InitMap(V, 0);
    } else {
        int N = V - 12;
        for(int a = 0; a < U; a++){
            mat[C[a]][D[a]] = true;
            mat[D[a]][C[a]] = true;
            cnt[C[a]]++;
            cnt[D[a]]++;
        }

        fill(is_orig, is_orig + V, true);

        int root = find(cnt, cnt + V, N + 10) - cnt;
        is_orig[root] = false;
        int special = -1;
        for(int a = 0; a < V; a++){
            if(a != root && !mat[root][a]){
                special = a;
                is_orig[special] = false;
                break;
            }
        }

        vector<int> orig_binary;
        for(int a = 0; a < V; a++){
            if(mat[special][a]){
                orig_binary.push_back(a);
                is_orig[a] = false;
            }
        }

        int start;
        for(int a = 0; a < V; a++){
            if(a == special || a == root){
                continue;
            }
            bool good = true;
            for(int i : orig_binary){
                good &= mat[i][a];
            }
            if(good){
                start = a;
                is_orig[start] = false;
                break;
            }
        }

        for(int i : orig_binary){
            for(int j : orig_binary){
                if(mat[i][j]){
                    adj[i].push_back(j);
                }
            }
        }

        int cur = -1, prv = -1;
        for(int i : orig_binary){
            if((int)adj[i].size() == 1){
                cur = i;
                break;
            }
        }

        vector<pii> binary;
        while(true){
            int used = 0;
            for(int a = 0; a < V; a++){
                if(is_orig[a] && mat[a][cur]){
                    used++;
                }
            }
            binary.push_back({cur, used});
            if(adj[cur][0] == prv){
                if((int)adj[cur].size() == 1){
                    break;
                } else {
                    prv = cur;
                    cur = adj[cur][1];
                }
            } else {
                prv = cur;
                cur = adj[cur][0];
            }
        }

        if(binary[0].second < binary.back().second){
            reverse(binary.begin(), binary.end());
        }

        binary.insert(binary.begin(), pii(start, -1));

        for(int a = 0; a < V; a++){
            if(!is_orig[a]){
                continue;
            }
            for(int i = 0; i < (int)binary.size(); i++){
                if(mat[a][binary[i].first]){
                    real_idx[a] |= 1 << i;
                }
            }
        }

        vector<pii> edges;
        for(int a = 0; a < U; a++){
            if(is_orig[C[a]] && is_orig[D[a]]){
                edges.push_back({real_idx[C[a]], real_idx[D[a]]});
            }
        }

        InitMap(N, edges.size());
        for(pii p : edges){
            MakeMap(p.first, p.second);
        }
    }
}
