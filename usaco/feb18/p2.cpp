#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
vector<int> adj[MAXN];

int cnt = 0;
bool vis[MAXN];
bool blocked[MAXN];
pair<char, int> oper[MAXN];

int dep[MAXN];

void find_dep(int pos, int par){
    dep[pos] = 0;
    for(int i : adj[pos]){
        if(i == par || blocked[i]){
            continue;
        }
        find_dep(i, pos);
        dep[pos] = max(dep[pos], dep[i] + 1);
    }
}

pii find_centroid(int pos, int par, int abv){
    pii best = pii(max(abv, dep[pos]), pos);
    
    int b1 = 0, b2 = 0;
    for(int i : adj[pos]){
        if(i == par || blocked[i]){
            continue;
        }
        if(dep[i] + 1 > b1){
            b2 = b1;
            b1 = dep[i] + 1;
        } else if (dep[i] + 1 > b2){
            b2 = dep[i] + 1;
        }
    }

    for(int i : adj[pos]){
        if(i == par || blocked[i]){
            continue;
        }
        if(dep[i] + 1 == b1){
            best = min(best, find_centroid(i, pos, max(abv, b2) + 1));
        } else {
            best = min(best, find_centroid(i, pos, max(abv, b1) + 1));
        }
    }   
    return best;
}

vector<pair<pii, int>> parents[MAXN];
void decomp_dfs(int pos, int par, int src, int src2, int par_dep){
    parents[pos].push_back({pii(src, src2), par_dep});
    for(int i : adj[pos]){
        if(i == par || blocked[i]){
            continue;
        }
        decomp_dfs(i, pos, src, src2, par_dep + 1);
    }
}

pii deepest[MAXN][2];
void decomp(int pos){
    find_dep(pos, -1);
    int centroid = find_centroid(pos, -1, 0).second;
    blocked[centroid] = true;

    for(int i : adj[centroid]){
        if(!blocked[i]){
            decomp_dfs(i, centroid, centroid, i, 1);
        }
    }

    for(int i : adj[centroid]){
        if(!blocked[i]){
            decomp(i);
        }
    }
}

int bcnt = 0;
int root_dist[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("newbarn.in", "r", stdin);
    freopen("newbarn.out", "w", stdout);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> oper[a].first;
        cin >> oper[a].second;
        if(oper[a].first == 'B'){
            cnt++;
            if(oper[a].second != -1){
                adj[oper[a].second].push_back(cnt);
                adj[cnt].push_back(oper[a].second);
				root_dist[cnt] = root_dist[oper[a].second] + 1;
            }
        }
    }
    for(int a = 1; a <= cnt; a++){
        if(!blocked[a]){
            decomp(a);
        }
    }
    for(int a = 0; a < N; a++){
        if(oper[a].first == 'B'){
            bcnt++;
            //cout << bcnt << " links to \n";
            for(pair<pii, int> p : parents[bcnt]){

                int root = p.first.first;
                int src = p.first.second;
                int dist = p.second;
                //cout << root << " from " << src << " dist " << dist << "\n";

                if(deepest[root][0].second == src){
                    deepest[root][0].first = max(deepest[root][0].first, dist);
                } else if(deepest[root][1].second == src){
                    deepest[root][1].first = max(deepest[root][1].first, dist);
                    if(deepest[root][1] > deepest[root][0]){
                        swap(deepest[root][0], deepest[root][1]);
                    }
                } else {
                    pii pr = pii(dist, src);
                    if (pr > deepest[root][0]){
                        deepest[root][1] = deepest[root][0];
                        deepest[root][0] = pr;
                    } else if(pr > deepest[root][1]){
                        deepest[root][1] = pr;
                    }
                }
            }
            //cout << "\n";
        } else {
            //cout << "Querying " << oper[a].second << "\n";
            int ans = max(deepest[oper[a].second][0].first, root_dist[oper[a].second]);
            for(pair<pii, int> p : parents[oper[a].second]){
                int root = p.first.first;
                int src = p.first.second;
                int dist = p.second;
                //cout << root << " from " << src << " dist " << dist << "\n";

                if(root <= bcnt){
                    //good
                    if(deepest[root][0].second == src){
                        ans = max(ans, dist + deepest[root][1].first);
                    } else {
                        ans = max(ans, dist + deepest[root][0].first);
                    }
                }
            }
            cout << ans << "\n";
        }
    }
}
