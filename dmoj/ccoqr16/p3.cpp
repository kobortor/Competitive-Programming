#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, M;

ll tri(ll x){
    return x * (x + 1) / 2;
}

map<ll, ll> mp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    while(M--){
        ll r, c;
        cin >> r >> c;
        mp[c] = max(mp[c], N - r + 1);
    }
    mp[N+1] = 0;

    ll ans = 0;

    ll prvx = 0;
    ll prvh = 0;
    for(auto au : mp){
        ans += tri(prvh) - tri(max(0ll, prvh - (au.first - prvx)));

        prvh = max(prvh - (au.first - prvx), au.second);
        prvx = au.first;
    }

    cout << ans;
}
