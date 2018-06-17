#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, L, W;

vector<ll> pos;

deque<ll> dq;

bool goodp(ll l, ll r){
    ll x = (l + r) / 2;
    ll y = x - l;
    return abs(x) < y * W;
}

bool good(ll l, ll r){
    return goodp(l, r) || goodp(l + L, r) || goodp(l, r + L) || goodp(l + L, r + L);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> L >> W;

    L *= 2;

    while(N--){
        ll x, v;
        cin >> x >> v;

        x *= 2;

        if(v == 1){
            pos.push_back(x);
        } else {
            dq.push_back(x);
        }
    }

    sort(allof(pos));
    sort(allof(dq));

    ll ans = 0;

    for(ll i : pos){
        while(!dq.empty() && !good(i, dq.front())){
            dq.pop_front();
        }
        while(!dq.empty() && !good(i, dq.back())){
            dq.pop_back();
        }
        ans += dq.size();
    }

    cout << ans;
}
