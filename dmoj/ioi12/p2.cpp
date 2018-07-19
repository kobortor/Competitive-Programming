#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N;
int dsu[MAXN];
vector<int> adj[MAXN];
vector<int> avail;
int color[MAXN];
bool allow[MAXN];
int col_cnt[MAXN];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

void Init(int _N){
    memset(color, -1, sizeof color);

    N = _N;
    for(int a = 0; a < N; a++){
        avail.push_back(a);
        dsu[a] = a;
    }
}

void limit(){
    for(int i = 0; i < (int)avail.size(); i++){
        if(!allow[avail[i]]){
            swap(avail[i], avail.back());
            avail.pop_back();
            i--;
        }
    }
}

void dfs_col(int pos, int col){
    color[pos] = col;
    col_cnt[col]++;

    for(int i : adj[pos]){
        if(color[i] != 0 && color[i] != col){
            if(color[i] != -1){
                col_cnt[color[i]]--;
            }

            dfs_col(i, col);
        }
    }
}

void add_to(int A, int B){
    int prvsz = avail.size();

    adj[A].push_back(B);

    if((int)adj[A].size() == 3){

        allow[A] = true;
        allow[adj[A][0]] = true;
        allow[adj[A][1]] = true;
        allow[adj[A][2]] = true;

        limit();

        allow[A] = false;
        allow[adj[A][0]] = false;
        allow[adj[A][1]] = false;
        allow[adj[A][2]] = false;
    }

    if(adj[A].size() == 4){
        allow[A] = true;

        limit();

        allow[A] = false;
    }

    if(prvsz != 1 && (int)avail.size() == 1){
        color[avail[0]] = 0;
        for(int i : adj[avail[0]]){
            dfs_col(i, i);
        }
    }
}

bool dfs_set(int pos, bool tp, int targ){
    allow[pos] = tp;

    if(pos == targ){
        return true;
    }

    bool found = false;
    for(int i : adj[pos]){
        if(allow[i] != tp){
            found |= dfs_set(i, tp, targ);
        }
    }

    if(!found){
        allow[pos] ^= 1;
    }

    return found;
}

void Link(int A, int B){
    if(avail.empty()){
        return;
    }

    add_to(A, B);
    add_to(B, A);

    int fa = find(A);
    int fb = find(B);

    if(avail.empty()){
        return;
    }

    if(fa == fb){
        if(color[A] == -1){
            dfs_set(A, true, B);
            limit();
            dfs_set(A, false, B);
        } else if (A != avail[0] && B != avail[0]) {
            if (color[A] == color[B]){
                avail.clear();
            } else {
                if(col_cnt[color[A]] < col_cnt[color[B]]){
                    dfs_col(A, color[B]);
                } else {
                    dfs_col(B, color[A]);
                }
            }
        }
    } else {
        dsu[fa] = fb;

        if((int)avail.size() == 1){
            if(A == avail[0]){
                dfs_col(B, B);
            } else if (B == avail[0]){
                dfs_col(A, A);
            } else if(color[A] != -1){
                dfs_col(A, color[A]);
            } else if (color[B] != -1){
                dfs_col(B, color[B]);
            }
        }
    }
}

int CountCritical(){
    return avail.size();
}
