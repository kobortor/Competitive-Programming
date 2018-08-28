#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 132675;

struct rect {
    int u, d, l, r;
    rect(){}
    rect(int U, int D, int L, int R){
        u = U;
        d = D;
        l = L;
        r = R;
    }

    rect inter(const rect &rr) const {
        rect res = *this;
        res.l = max(res.l, rr.l);
        res.r = min(res.r, rr.r);
        res.d = max(res.d, rr.d);
        res.u = min(res.u, rr.u);
        return res;
    }
};

int N;
rect input[MAXN], prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    prefix[0] = rect(1e9, -1e9, -1e9, 1e9);

    for(int a = 1; a <= N; a++){
        cin >> input[a].l;
        cin >> input[a].d;
        cin >> input[a].r;
        cin >> input[a].u;

        prefix[a] = prefix[a - 1].inter(input[a]);
    }

    rect back(1e9, -1e9, -1e9, 1e9);

    for(int a = N; a >= 1; a--){
        rect tmp = back.inter(prefix[a - 1]);
        if(tmp.l <= tmp.r && tmp.d <= tmp.u){
            cout << tmp.l << " " << tmp.d << endl;
            return 0;
        }

        back = back.inter(input[a]);
    }
}
