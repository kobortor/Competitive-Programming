#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
vector<int> adj[MAXN];
char tp[MAXN];

bool blocked[MAXN];
int sz[MAXN];

void find_dep(int pos, int par){
    sz[pos] = 1;
    for(int i : adj[pos]){
        if(i != par && !blocked[i]){
            find_dep(i, pos);
            sz[pos] += sz[i];
        }
    }
}

pii best;
void find_centroid(int pos, int abv, int par){
    int largest = abv;
    for(int i : adj[pos]){
        if(i != par && !blocked[i]){
            largest = max(largest, sz[i]);
        }
    }
    best = min(best, pii(largest, pos));
    for(int i : adj[pos]){
        if(i != par && !blocked[i]){
            find_centroid(i, abv + sz[pos] - sz[i], pos);
        }
    }
}

ll total[1 << 20];
ll ans[1 << 20];

ll help_solve(int pos, int par, int state){
    state ^= 1 << (tp[pos] - 'a');

    ll tmp = total[state];
    for(int a = 0; a < 20; a++) {
        if(total[state ^ (1 << a)]){
        }
        tmp += total[state ^ (1 << a)];
    }
    for(int i : adj[pos]){
        if(i != par && !blocked[i]){
            tmp += help_solve(i, pos, state);
        }
    }
    ans[pos] += tmp;
    return tmp;
}

ll root_solve(int pos, int par, int state){
    state ^= 1 << (tp[pos] - 'a');
    ll tmp = 0;
    if(state == 0 || (state & -state) == state){
        tmp++;
    }
    for(int i : adj[pos]){
        if(i != par && !blocked[i]){
            tmp += root_solve(i, pos, state);
        }
    }
    ans[pos] += tmp;
    return tmp;
}

//0 is sub mode
//1 is add mode
void init_solve(int pos, int par, int state, int mode){
    state ^= 1 << (tp[pos] - 'a');
    if(mode){
        total[state]++;
    } else {
        total[state]--;
    }

    for(int i : adj[pos]){
        if(i != par && !blocked[i]){
            init_solve(i, pos, state, mode);
        }
    }
}

void solve(int centroid){
    for(int i : adj[centroid]) {
        if(!blocked[i]){
            init_solve(i, centroid, 1 << (tp[centroid] - 'a'), true);
        }
    }
    
    ll centroid_add = 0;
    for(int i : adj[centroid]) {
        if(!blocked[i]){
            init_solve(i, centroid, 1 << (tp[centroid] - 'a'), false);

            centroid_add += help_solve(i, centroid, 0);

            init_solve(i, centroid, 1 << (tp[centroid] - 'a'), true);
        }
    }
    root_solve(centroid, -1, 0);
    ans[centroid] += centroid_add / 2;

    for(int i : adj[centroid]) {
        if(!blocked[i]){
            init_solve(i, centroid, 1 << (tp[centroid] - 'a'), false);
        }
    }
}

void divide_tree(int start){
    best = pii(0x3f3f3f3f, 0);
    find_dep(start, -1);
    find_centroid(start, 0, -1);

    int centroid = best.second;
    solve(centroid);

    blocked[centroid] = true;
    for(int i : adj[centroid]) {
        if(!blocked[i]) {
            divide_tree(i);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> (tp + 1);
    divide_tree(1);
    for(int a = 1; a <= N; a++){
        cout << ans[a] << " ";
    }
}
