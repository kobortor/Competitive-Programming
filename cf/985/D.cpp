#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, H;

ll solve(ll wid){
    if(wid <= H){
        if((double)wid * (wid + 1) / 2 > 5e18){
            return 5e18;
        } else {
            return min((ll)5e18, wid * (wid + 1) / 2);
        }
    } else {
        ll remain = wid - H;

        double tmpD = 0;
        ll tmpL = 0;
        tmpD += (double)H * (H + 1) / 2;
        tmpL += H * (H + 1) / 2;

        tmpD += (double)remain * H;
        tmpL += remain * H;

        if(remain % 2 == 1) {
            tmpD += (double)(remain / 2) * (remain / 2 + 1);
            tmpL += (remain / 2) * (remain / 2 + 1);
        } else {
            tmpD += (double)(remain / 2) * (remain / 2);
            tmpL += (remain / 2) * (remain / 2);
        }

        if(tmpD > 5e18){
            return 5e18;
        } else {
            return min((ll)5e18, tmpL);
        }
    }
}

bool good(ll wid){
    return solve(wid) >= N;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> H;

    ll lo = 1, hi = 1e18;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;

        if(good(mid)){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    assert(good(lo));
    assert(!good(lo - 1));
    cout << lo;
}
