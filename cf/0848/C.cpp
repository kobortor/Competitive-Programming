#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const int BLOCK = 1 << 12;

int N, M;
struct query {
    int tp, v1, v2;
}queries[MAXN];
int shape[MAXN];

ll out[MAXN];
set<int> avail[MAXN];
int prv[MAXN], nxt[MAXN];
int lhs[MAXN], rhs[MAXN];

pii change[MAXN][2];
pii color_change[MAXN];
ll ans = 0;

void remove(int type, int pos){
    ans -= max(0, rhs[type] - lhs[type]);
    if(lhs[type] == rhs[type]){
        lhs[type] = N + 1;
        rhs[type] = 0;
        return;
    }
    if(pos == rhs[type]) rhs[type] = prv[pos];
    if(pos == lhs[type]) lhs[type] = nxt[pos];
    ans += max(0, rhs[type] - lhs[type]);
}

void add(int type, int pos){
    ans -= max(0, rhs[type] - lhs[type]);
    lhs[type] = min(lhs[type], pos);
    rhs[type] = max(rhs[type], pos);
    ans += max(0, rhs[type] - lhs[type]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        avail[a].insert(0);
        avail[a].insert(N+1);       
    }

    for(int a = 1; a <= N; a++){
        cin >> shape[a];
        avail[shape[a]].insert(a);

        lhs[a] = N + 1;
        rhs[a] = 0;
    }

    for(int a = 1; a <= N; a++){
        auto iter = avail[shape[a]].find(a);
        prv[a] = *prev(iter);
        nxt[a] = *next(iter);
    }
    
    for(int a = 1; a <= M; a++){
        out[a] = -1;
        cin >> queries[a].tp;
        cin >> queries[a].v1;
        cin >> queries[a].v2;
        if(queries[a].tp == 1){
            int pos = queries[a].v1;
            int old_col = shape[pos];
            int new_col = queries[a].v2;
            color_change[a] = pii(old_col, new_col);
            if(old_col != new_col){
                auto iter = avail[old_col].find(pos);
                change[a][0] = pii(*prev(iter), *next(iter));
                avail[old_col].erase(iter);

                iter = avail[new_col].insert(pos).first;
                change[a][1] = pii(*prev(iter), *next(iter));

                shape[pos] = new_col;
            }
        }
    }

    for(int a = M; a >= 1; a--){
        if(queries[a].tp == 1){
            int pos = queries[a].v1;
            int new_col = color_change[a].first;
            shape[pos] = new_col;
        }
    }

    int lbnd = 1;
    int rbnd = 0;
    for(int lblock = 0; lblock * BLOCK <= N; lblock++){
        for(int rblock = lblock; rblock * BLOCK <= N; rblock++){
            for(int a = 1; a <= M; a++){
                if(queries[a].tp == 1){
                    int pos = queries[a].v1;
                    int old_col = color_change[a].first;
                    int new_col = color_change[a].second;
                    if(old_col != new_col){
                        if(lbnd <= pos && pos <= rbnd){
                            remove(old_col, pos);
                        }

                        pii old_pos = change[a][0];
                        pii new_pos = change[a][1];

                        nxt[old_pos.first] = old_pos.second;
                        prv[old_pos.second] = old_pos.first;

                        nxt[new_pos.first] = pos;
                        prv[new_pos.second] = pos;

                        prv[pos] = new_pos.first;
                        nxt[pos] = new_pos.second;

                        if(lbnd <= pos && pos <= rbnd){
                            add(new_col, pos);
                        }
                        shape[pos] = new_col;
                    }
                } else {
                    int lft = queries[a].v1 / BLOCK;
                    int rht = queries[a].v2 / BLOCK;
                    if(lft == lblock && rht == rblock){
                        while(rbnd < queries[a].v2){
                            rbnd++;
                            add(shape[rbnd], rbnd);
                        }
                        while(queries[a].v1 < lbnd){
                            lbnd--;
                            add(shape[lbnd], lbnd);
                        }
                        while(queries[a].v2 < rbnd){
                            remove(shape[rbnd], rbnd);
                            rbnd--;
                        }
                        while(lbnd < queries[a].v1){
                            remove(shape[lbnd], lbnd);
                            lbnd++;
                        }
                        out[a] = ans;
                    }
                }
            }
            
            for(int a = M; a >= 1; a--){
                if(queries[a].tp == 1){
                    int pos = queries[a].v1;
                    int old_col = color_change[a].second;
                    int new_col = color_change[a].first;
                    if(old_col != new_col){
                        if(lbnd <= pos && pos <= rbnd){
                            remove(old_col, pos);
                        }

                        pii old_pos = change[a][1];
                        pii new_pos = change[a][0];

                        nxt[old_pos.first] = old_pos.second;
                        prv[old_pos.second] = old_pos.first;

                        nxt[new_pos.first] = pos;
                        prv[new_pos.second] = pos;

                        prv[pos] = new_pos.first;
                        nxt[pos] = new_pos.second;

                        if(lbnd <= pos && pos <= rbnd){
                            add(new_col, pos);
                        }
                        shape[pos] = new_col;
                    }
                }
            }
        }
    }
    for(int a = 1; a <= M; a++){
        if(queries[a].tp == 2){
            cout << out[a] << "\n";
        }
    }
}
