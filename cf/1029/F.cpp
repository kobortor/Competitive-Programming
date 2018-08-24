#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll A, B;
vector<pll> factor(ll x){
    vector<pll> ans;
    for(ll a = 1; a * a <= x; a++){
        if(x % a == 0){
            ans.push_back({a, x / a});
        }
    }
    return move(ans);
}

bool solve(ll x, ll y, const vector<pll> &F){
    int lo = 0, hi = F.size() - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(F[mid].first <= x && F[mid].second <= y){
            return true;
        }

        if(F[mid].first > x){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> A >> B;
    vector<pll> FAB = factor(A + B);
    vector<pll> FA = factor(A);
    vector<pll> FB = factor(B);

    ll ans = 1e18;
    for(pll p : FAB){
        if(solve(p.first, p.second, FA) || solve(p.first, p.second, FB)){
            ans = min(ans, 2 * (p.first + p.second));
        }
    }

    cout << ans;
}
