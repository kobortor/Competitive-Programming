#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N;

bool check(ll K){
    ll eat = 0;
    ll tmp = N;
    while(tmp){
        eat += min(tmp, K);
        tmp = max(0ll, tmp - K);
        tmp = tmp - tmp / 10;
    }

    return eat * 2 >= N;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    ll lo = 1, hi = N;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(!check(mid)){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo;
}
