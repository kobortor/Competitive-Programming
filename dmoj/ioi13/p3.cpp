#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXR = 5005;
const int MAXC = 205;

int R, C;
int **H, **V;

struct matrix {
    vector<vector<int>> data;
    matrix() : data(C, vector<int>(C)){}
    vector<int>& operator[](int row){
        return data[row];
    }
};

matrix make_matrix(int row){
    matrix mat;
    for(int a = 0; a < C; a++){
        mat[a][a] = V[row][a];
        for(int b = a + 1, tot = 0; b < C; b++){
            tot += H[row][b - 1];
            mat[a][b] = tot + V[row][b];
        }
        for(int b = a - 1, tot = 0; b >= 0; b--){
            tot += H[row][b];
            mat[a][b] = tot + V[row][b];
        }
    }
    return mat;
}

void search(int src, int rangeL, int rangeR, int targL, int targR, const matrix &lft, const matrix &rht, matrix &soln){
    if(targL > targR){
        return;
    }

    int targMid = (targL + targR) / 2;

    int bestv = 0x3f3f3f3f;
    int bestpos = rangeL;
    for(int a = rangeL; a <= rangeR; a++){
        int val = lft.data[src][a] + rht.data[a][targMid];
        if(val < bestv){
            bestv = val;
            bestpos = a;
        }
    }

    soln[src][targMid] = bestv;

    search(src, rangeL, bestpos, targL, targMid - 1, lft, rht, soln);
    search(src, bestpos, rangeR, targMid + 1, targR, lft, rht, soln);
}

matrix combine(const matrix &lft, const matrix &rht){
    matrix mat;
    for(int a = 0; a < C; a++){
        search(a, 0, C - 1, 0, C - 1, lft, rht, mat);
    }
    return mat;
}

const int SEGTREE = 1600;
const int FAT = 12;
struct {
    int l, r;
    matrix mat;
} tr[SEGTREE];

void build(int l, int r, int pos){
    assert(pos < SEGTREE);
    tr[pos].l = l;
    tr[pos].r = r;
    if(r - l + 1 < FAT){
        tr[pos].mat = make_matrix(l);
        for(int a = l + 1; a <= r; a++){
            tr[pos].mat = combine(tr[pos].mat, make_matrix(a));
        }
    } else {
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
        tr[pos].mat = combine(tr[pos << 1].mat, tr[pos << 1 | 1].mat);
    }
}

void update(int loc, int pos){
    if(tr[pos].r - tr[pos].l + 1 < FAT){
        tr[pos].mat = make_matrix(tr[pos].l);
        for(int a = tr[pos].l + 1; a <= tr[pos].r; a++){
            tr[pos].mat = combine(tr[pos].mat, make_matrix(a));
        }
        return;
    }

    int mid = tr[pos << 1].r;
    if(loc <= mid){
        update(loc, pos << 1);
    } else {
        update(loc, pos << 1 | 1);
    }
    tr[pos].mat = combine(tr[pos << 1].mat, tr[pos << 1 | 1].mat);
}


void init(int _R, int _C, int _H[5000][200], int _V[5000][200]){
    R = _R;
    C = _C;

    H = new int*[R];
    for(int a = 0; a < R; a++){
        H[a] = new int[C - 1];
        copy(_H[a], _H[a] + C - 1, H[a]);
    }

    V = new int*[R];
    for(int a = 0; a < R - 1; a++){
        V[a] = new int[C];
        copy(_V[a], _V[a] + C, V[a]);
    }

    build(0, _R - 2, 1);
}

void changeH(int P, int Q, int W){
    H[P][Q] = W;

    update(P, 1);
}
void changeV(int P, int Q, int W){
    V[P][Q] = W;

    update(P, 1);
}
int escape(int V1, int V2){
    int ans = tr[1].mat[V1][V2];
    for(int a = V2 + 1, tot = 0; a < C; a++){
        tot += H[R - 1][a - 1];
        ans = min(ans, tr[1].mat[V1][a] + tot);
    }

    for(int a = V2 - 1, tot = 0; a >= 0; a--){
        tot += H[R - 1][a];
        ans = min(ans, tr[1].mat[V1][a] + tot);
    }
    return ans;
}
