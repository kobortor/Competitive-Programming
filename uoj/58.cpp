#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

//just play around with this number until you pass
const int BLOCK = 1 << 11;

int N, M, Q;

vector<int> adj[MAXN];
ll mult[MAXN];
ll taste[MAXN];
int color[MAXN];

int eid = 1;
int euler[MAXN];
int euler_end[MAXN];

int dep[MAXN];
int par[MAXN];

void euler_dfs(int pos){
    euler[pos] = eid++;
    for(int i : adj[pos]){
        if(i == par[pos]){
            continue;
        }
        par[i] = pos;
        dep[i] = dep[pos] + 1;
        euler_dfs(i);
    }
    euler_end[pos] = eid - 1;
}

ll sum = 0;
int query[MAXN][3];
int freq[MAXN]; //how many times a color is used
int used[MAXN]; //if a node is used
ll out[MAXN];

void remove(int pos){  
    int col = color[pos];
    if(freq[col] > 0){
        ll chng = mult[col] * taste[freq[col]];
        sum -= chng;
    }
    freq[col]--;
    used[pos]--;
}
void add(int pos){
    int col = color[pos];
    freq[col]++;
    used[pos]++;
    if(freq[col] > 0){
        ll chng = mult[col] * taste[freq[col]];
        sum += chng;
    }
}

void update(int pos, int col){
    bool USED = used[pos];
    if(USED){
        remove(pos);
    }
    color[pos] = col;
    if(USED){
        add(pos);
    }
}

void join(int src, int targ, int other){
    bool seen_other = false;
    while(src != targ){
        if(dep[src] < dep[targ]){
            swap(src, targ);
        }
        if(!seen_other && euler[src] <= euler[other] && euler[other] <= euler_end[src]){
            seen_other = true;
        } else if(used[src]){
            remove(src);
        } else {
            add(src);
        }

        src = par[src];
    }

    if(!seen_other){
    } else if(used[src]){
        remove(src);
    } else {
        add(src);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M >> Q;

    for(int a = 1; a <= M; a++){
        cin >> mult[a];
    }
    for(int a = 1; a <= N; a++){
        cin >> taste[a];
    }
    for(int a = 1; a < N; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int a = 1; a <= N; a++){
        cin >> color[a];
    }
    euler_dfs(1);

    vector<pii> backtrace;
    for(int a = 1; a <= Q; a++){
        cin >> query[a][0];
        cin >> query[a][1];
        cin >> query[a][2];

        if(query[a][0] == 0){
            backtrace.push_back(pii(query[a][1], color[query[a][1]]));
            color[query[a][1]] = query[a][2];
        }
    }

    reverse(allof(backtrace));
    for(pii p : backtrace){
        color[p.first] = p.second;
    }

    int u = 1, v = 1;
    add(1);
    
    for(int a = 0; a * BLOCK <= N; a++){
        for(int b = 0; b * BLOCK <= N; b++){
            for(int c = 1; c <= Q; c++){
                if(query[c][0] == 0){
                    update(query[c][1], query[c][2]);
                } else {
                    int eu = euler[query[c][1]] / BLOCK;
                    int ev = euler[query[c][2]] / BLOCK;
                    if(eu == a && ev == b){
                        //good
                        join(u, query[c][1], v);
                        u = query[c][1];

                        join(v, query[c][2], u);
                        v = query[c][2];

                        out[c] = sum;
                    }
                }
            }
            for(pii p : backtrace){
                update(p.first, p.second);
            }
        }
    }
    for(int a = 1; a <= Q; a++){
        if(query[a][0] == 1){
            cout << out[a] << "\n";
        }
    }
}
