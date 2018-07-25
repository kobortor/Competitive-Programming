#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

struct {
    int l, r, g, c;
} tr[MAXN * 4];

int gcd(int x, int y){
    while(x % y){
        x %= y;
        swap(x, y);
    }
    return y;
}

int N;

void pushup(int pos){
    tr[pos].g = gcd(tr[pos << 1].g, tr[pos << 1 | 1].g);
    tr[pos].c = 0;

    if(tr[pos << 1].g == tr[pos].g){
        tr[pos].c += tr[pos << 1].c;
    }
    if(tr[pos << 1 | 1].g == tr[pos].g){
        tr[pos].c += tr[pos << 1 | 1].c;
    }
}

int val[MAXN];
void build(int l, int r, int pos){
    tr[pos].l = l;
    tr[pos].r = r;

    if(l == r){
        cin >> val[l];
        tr[pos].g = val[l];
        tr[pos].c = 1;
        return;
    } else {
        int mid = (l + r) / 2;
        build(l, mid, pos << 1);
        build(mid + 1, r, pos << 1 | 1);
        pushup(pos);
    }
}

int queryL(int loc, int g, int pos){
    if(tr[pos].g % g == 0){
        return tr[pos].l;
    }
    if(tr[pos].l == tr[pos].r){
        return tr[pos].l + 1;
    }

    int mid = tr[pos << 1].r;
    if(loc <= mid){
        return queryL(loc, g, pos << 1);
    } else {
        int tmp = queryL(loc, g, pos << 1 | 1);
        if(tmp == mid + 1){
            return queryL(loc, g, pos << 1);
        } else {
            return tmp;
        }
    }
}

int queryR(int loc, int g, int pos){
    if(tr[pos].g % g == 0){
        return tr[pos].r;
    }
    if(tr[pos].l == tr[pos].r){
        return tr[pos].r - 1;
    }

    int mid = tr[pos << 1].r;
    if(loc > mid){
        return queryR(loc, g, pos << 1 | 1);
    } else {
        int tmp = queryR(loc, g, pos << 1);
        if(tmp == mid){
            return queryR(loc, g, pos << 1 | 1);
        } else {
            return tmp;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    build(1, N, 1);

    int bestlen = -1;
    vector<int> ans;

    for(int a = 1; a <= N; a++){
        int lft = queryL(a, val[a], 1);
        int rht = queryR(a, val[a], 1);
        if(rht - lft > bestlen){
            bestlen = rht - lft;
            ans.clear();
        }
        if(rht - lft == bestlen){
            ans.push_back(lft);
        }
    }

    sort(allof(ans));
    ans.erase(unique(allof(ans)), ans.end());

    cout << ans.size() << " " << bestlen << "\n";
    for(int i : ans){
        cout << i << " ";
    }
}
