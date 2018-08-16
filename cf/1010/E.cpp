#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int xm, ym, zm, n, m, k;

struct {
    int l, r, lzlow, lztop, lowv, topv;
} tr[MAXN * 4];

void pushdown(int pos){
    if(tr[pos].l != tr[pos].r){
        tr[pos << 1].lzlow = max(tr[pos << 1].lzlow, tr[pos].lzlow);
        tr[pos << 1].lowv = max(tr[pos << 1].lowv, tr[pos].lzlow);
        tr[pos << 1].lztop = min(tr[pos << 1].lztop, tr[pos].lztop);
        tr[pos << 1].topv = min(tr[pos << 1].topv, tr[pos].lztop);

        tr[pos << 1 | 1].lzlow = max(tr[pos << 1 | 1].lzlow, tr[pos].lzlow);
        tr[pos << 1 | 1].lowv = max(tr[pos << 1 | 1].lowv, tr[pos].lzlow);
        tr[pos << 1 | 1].lztop = min(tr[pos << 1 | 1].lztop, tr[pos].lztop);
        tr[pos << 1 | 1].topv = min(tr[pos << 1 | 1].topv, tr[pos].lztop);
    }
}

void pushup(int pos){
    tr[pos].lowv = max(tr[pos << 1].lowv, tr[pos << 1 | 1].lowv);
    tr[pos].topv = min(tr[pos << 1].topv, tr[pos << 1 | 1].topv);
}

void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;
    tr[pos].lzlow = -1e9;
    tr[pos].lowv = -1e9;

    tr[pos].lztop = +1e9;
    tr[pos].topv = +1e9;

    if(l != r){
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
    }
}

void update(int l, int r, int lowv, int topv, int pos){
    pushdown(pos);
    if(tr[pos].l == l && tr[pos].r == r){
        tr[pos].lzlow = max(tr[pos].lzlow, lowv);
        tr[pos].lowv = max(tr[pos].lowv, lowv);

        tr[pos].lztop = min(tr[pos].lztop, topv);
        tr[pos].topv = min(tr[pos].topv, topv);
        return;
    }

    int mid = tr[pos << 1].r;
    if(r <= mid){
        update(l, r, lowv, topv, pos << 1);
    } else if (l > mid){
        update(l, r, lowv, topv, pos << 1 | 1);
    } else {
        update(l, mid, lowv, topv, pos << 1);
        update(mid + 1, r, lowv, topv, pos << 1 | 1);
    }
    
    pushup(pos);
}

pii query(int loc, int pos){
    pushdown(pos);
    if(tr[pos].l == tr[pos].r){
        return pii(tr[pos].lowv, tr[pos].topv);
    }

    int mid = tr[pos << 1].r;
    pii ans;
    if(loc <= mid){
        ans = query(loc, pos << 1);
    } else {
        ans = query(loc, pos << 1 | 1);
    }
    pushup(pos);
    return ans;
}

struct coord {
    int x, y, z;
    bool operator<(const coord &c) const {
        return x < c.x;
    }
};

int xa = 1e9, xb = -1, ya = 1e9, yb = -1, za = 1e9, zb = -1;

vector<coord> open, closed;
vector<coord> lft, mid, rht;
vector<pair<coord, int>> lftq, midq, rhtq;

void fill_point(coord c){
    int yl, yr, zl, zr;
    if(c.y < ya){
        yl = 1, yr = c.y;
    } else if (ya <= c.y && c.y <= yb){
        yl = 1, yr = MAXN;
    } else {
        yl = c.y, yr = MAXN;
    }

    if(c.z < za){
        zl = c.z, zr = MAXN; //FIX THIS PART
    } else if (za <= c.z && c.z <= zb){
        zl = MAXN, zr = MAXN;
    } else {
        zl = 0, zr = c.z;
    }

    update(yl, yr, zl, zr, 1);
}

//0 - NO
//1 - MAYBE
//2 - YES
int out[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> xm >> ym >> zm >> n >> m >> k;

    while(n--){
        int x, y, z;
        cin >> x >> y >> z;

        xa = min(xa, x);
        xb = max(xb, x);

        ya = min(ya, y);
        yb = max(yb, y);

        za = min(za, z);
        zb = max(zb, z);
    }

    while(m--){
        coord c;
        cin >> c.x >> c.y >> c.z;
        if(xa <= c.x && c.x <= xb && ya <= c.y && c.y <= yb && za <= c.z && c.z <= zb){
            cout << "INCORRECT\n";
            return 0;
        }

        if(c.x < xa){
            lft.push_back(c);
        } else if (xa <= c.x && c.x <= xb){
            mid.push_back(c);
        } else {
            rht.push_back(c);
        }
    }

    sort(allof(lft));
    reverse(allof(lft));

    sort(allof(rht));

    for(int a = 0; a < k; a++){
        coord c;
        cin >> c.x >> c.y >> c.z;
        if(xa <= c.x && c.x <= xb && ya <= c.y && c.y <= yb && za <= c.z && c.z <= zb){
            out[a] = 2;
        } else if(c.x < xa){
            lftq.push_back({c, a});
        } else if (xa <= c.x && c.x <= xb){
            midq.push_back({c, a});
        } else {
            rhtq.push_back({c, a});
        }
    }
    
    sort(allof(lftq));
    reverse(allof(lftq));

    sort(allof(rhtq));

    build(1, MAXN, 1);
    for(coord c : mid){
        fill_point(c);
    }

    for(auto au : midq){
        pii res = query(au.first.y, 1);
        out[au.second] = res.first < au.first.z && au.first.z < res.second;
    }

    for(int a = 0, b = 0; a < (int)rhtq.size(); a++){
        while(b < (int)rht.size() && rht[b].x <= rhtq[a].first.x){
            fill_point(rht[b]);
            b++;
        }

        pii res = query(rhtq[a].first.y, 1);
        out[rhtq[a].second] = res.first < rhtq[a].first.z && rhtq[a].first.z < res.second;
    }

    build(1, MAXN, 1);
    for(coord c : mid){
        fill_point(c);
    }
    for(int a = 0, b = 0; a < (int)lftq.size(); a++){
        while(b < (int)lft.size() && lft[b].x >= lftq[a].first.x){
            fill_point(lft[b]);
            b++;
        }

        pii res = query(lftq[a].first.y, 1);
        out[lftq[a].second] = res.first < lftq[a].first.z && lftq[a].first.z < res.second;
    }

    cout << "CORRECT\n";
    for(int a = 0; a < k; a++){
        if(out[a] == 0){
            cout << "CLOSED\n";
        } else if (out[a] == 1){
            cout << "UNKNOWN\n";
        } else {
            cout << "OPEN\n";
        }
    }
}
