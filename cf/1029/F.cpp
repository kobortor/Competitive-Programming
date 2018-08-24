#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll A, B;
vector<ll> factor(ll x){
    vector<ll> ans;
    for(ll a = 1; a * a <= x; a++){
        if(x % a == 0){
            ans.push_back(a);
        }
    }
    return ans;
}

bool solve(ll x, ll y, const vector<ll> &F, ll V){
    if(x > y){
        swap(x, y);
    }

    int lo = 0, hi = F.size() - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        ll i = F[mid];
        ll j = V / F[mid];
        assert(i <= j);

        if(i <= x && j <= y){
            return true;
        }

        if(i > x){
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
    vector<ll> FAB = factor(A + B);
    vector<ll> FA = factor(A);
    vector<ll> FB = factor(B);

    sort(allof(FAB));
    sort(allof(FA));
    sort(allof(FB));

    ll ans = 1e18;
    for(ll x : FAB){
        ll y = (A + B) / x;

        if(solve(x, y, FA, A) || solve(x, y, FB, B)){
            ans = min(ans, 2 * (x + y));
        }
    }

    cout << ans;
}
