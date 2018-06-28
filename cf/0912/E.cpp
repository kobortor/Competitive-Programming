#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K;
vector<ll> primes[2], v0, v1;

bool is_overflow(const ll &x, const ll &y){
    //be very careful, the compiler may optimize this away
    ll tmp = x * y;
    return tmp / y != x || tmp / x != y;
}

void get_combos(vector<ll> &res, vector<ll> moves){
    const ll LIM = 1e18 + 18;
    res.push_back(1);
    while(true){
        ll best = LIM + 1;
        ll targ = res.back();

        for(ll x : moves){
            auto iter = upper_bound(res.begin(), res.end(), targ / x);
            if(iter != res.end() && !is_overflow(x, *iter)){
                best = min(best, x * *iter);
            }
        }

        if(best > LIM){
            break;
        } else {
            res.push_back(best);
        }
    }
}

ll num_leq(ll guess){
    int idx = 0;
    ll ans = 0;

    for(const ll &x : v0){
        while(idx != (int)v1.size()){
            if(is_overflow(x, v1[idx]) || v1[idx] * x > guess){
                idx++;
            } else {
                break;
            }
        }
        ans += v1.size() - idx;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;

    for(int a = 0; a < N; a++){
        ll x;
        cin >> x;
        primes[a % 2].push_back(x);
    }
    cin >> K;

    get_combos(v0, primes[0]);
    get_combos(v1, primes[1]);

    reverse(v1.begin(), v1.end());

    ll l = 1, r = 1e18 + 18;
    while(l <= r){
        ll mid = (l + r) >> 1;
        ll cnt = num_leq(mid);
        
        if(cnt < K){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << l;
}

