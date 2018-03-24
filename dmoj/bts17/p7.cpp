#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, S;
vector<int> adj[MAXN];

int dep[MAXN];
int jmp[MAXN][20];
void dfs1(int pos){
    for(int a = 1; jmp[pos][a - 1] != 0 && a < 20; a++){
        jmp[pos][a] = jmp[jmp[pos][a - 1]][a - 1];
    }
    for(int i : adj[pos]){
        if(i != jmp[pos][0]){
            jmp[i][0] = pos;
            dep[i] = dep[pos] + 1;
            dfs1(i);
        }
    }
}

//<pos, dist>
pii lca(int u, int v){
    if(u == v){
        return pii(u, 0);
    }
    if(dep[u] < dep[v]){
        swap(u, v);
    }
    int dist = 0;
    int diff = dep[u] - dep[v];
    for(int a = 0; a < 20; a++){
        if(diff & (1 << a)){
            dist += 1 << a;
            u = jmp[u][a];
        }
    }
    if(u == v){
        return pii(u, dist);
    }

    for(int a = 19; a >= 0; a--){
        if(jmp[u][a] != jmp[v][a]){
            u = jmp[u][a];
            v = jmp[v][a];

            dist += 2 << a;
        }
    }
    dist += 2;
    return pii(jmp[u][0], dist);
}

ll incv[MAXN];
ll carry[MAXN];

ll ans[MAXN];

void dfs2(int pos){
    for(int i : adj[pos]){
        if(i != jmp[pos][0]){
            dfs2(i);
            carry[pos] += carry[i] + incv[i];
            incv[pos] += incv[i];
        }
    }
    ans[pos] = carry[pos];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> S;
    for(int a = 1; a < N; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1);
    
    while(S--){
        int a, b, t;
        cin >> a >> b >> t;

        pii ab = lca(a, b);
        pii abt = lca(ab.first, t);
        if(ab.first != t && ab.first == abt.first){
            //cout << "Type 1" << endl;
            //t is in the subtree
            pii tmpa = lca(a, t);
            pii tmpb = lca(b, t);

            incv[a]--;
            incv[b]--;
            carry[a] += tmpa.second;
            carry[b] += tmpb.second;

            if(dep[tmpa.first] > dep[tmpb.first]){
                //T is on A's side
                incv[tmpa.first] += 2;
            } else {
                //T is on B's side
                incv[tmpb.first] += 2;
            }
            carry[ab.first] -= abt.second;
            carry[jmp[ab.first][0]] -= abt.second;

        } else {
            //cout << "Type 2" << endl;
            incv[a]--;
            incv[b]--;
            incv[ab.first] += 2;
            
            carry[a] += abt.second + lca(a, ab.first).second;
            carry[b] += abt.second + lca(b, ab.first).second;

            carry[ab.first] -= abt.second;
            carry[jmp[ab.first][0]] -= abt.second;
        }
    }
    dfs2(1);
    for(int a = 1; a <= N; a++){
        cout << ans[a] << " ";
        //cout << carry[a] << " " << incv[a] << endl;
    }
}
