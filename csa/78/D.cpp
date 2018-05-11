#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5;
const int MAXM = 2e4 + 4;

int N, M, Q;
unsigned grid[MAXN][MAXM];

struct node {
    int l, r;
    int mat[MAXN][MAXN];
}tr[MAXM * 4];

void pushup(int pos){
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            tr[pos].mat[a][b] = -1000000001;
            for(int c = 0; c < N; c++){
                tr[pos].mat[a][b] = max(tr[pos].mat[a][b], tr[pos << 1].mat[a][c] + tr[pos << 1 | 1].mat[c][b]);
            }
        }
    }
}

void init(int pos){
    int idx = tr[pos].r;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            if(abs(a-b) <= 1){
                tr[pos].mat[a][b] = grid[a][idx];
            } else {
                tr[pos].mat[a][b] = -1000000001;
            }
        }
    }
}

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;

    if(l == r){
        init(pos);
    } else {
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
        pushup(pos);
    }
}

void update(int id, int pos){
    if(tr[pos].l == tr[pos].r){
        init(pos);
        return;
    }

    if(id <= tr[pos << 1].r){
        update(id, pos << 1);
    } else {
        update(id, pos << 1 | 1);
    }
    pushup(pos);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            cin >> grid[a][b];
        }
    }
    build(0, M - 1, 1);
    while(Q--){
        int R, C, T;
        cin >> R >> C >> T;
        grid[R-1][C-1] = T;
        update(C-1, 1);
        int best = -1;
        for(int a = 0; a < N; a++){
            for(int b = 0; b < N; b++){
                best = max(best, tr[1].mat[a][b]);
            }
        }
        cout << best << "\n";
    }
}
