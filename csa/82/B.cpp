#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll req[4];
ll cost[4];
ll bundle;

ll check(ll cnt){
    ll ans = cnt * bundle;
    for(int a = 0; a < 4; a++){
        ans += max(0ll, req[a] - cnt) * cost[a];
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 0; a < 4; a++){
        cin >> req[a];
    }

    for(int a = 0; a < 4; a++){
        cin >> cost[a];
    }

    cin >> bundle;

    ll ans = check(0);
    for(int a = 0; a < 4; a++){
        ans = min(ans, check(req[a]));
    }

    cout << ans;
}
