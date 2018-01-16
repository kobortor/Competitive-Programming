#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 32;

ll N, L;
ll price[MAXN];

ll get_price(ll x){
    ll ans = 0;
    for(int a = 0; a < 32; a++){
        if(x & (1 << a)){
            ans += price[a];
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    memset(price, 0x3f, sizeof price);
    
    cin >> N >> L;
    for(int a = 0; a < N; a++){
        cin >> price[a];
    }

    for(int a = 1; a < 32; a++){
        price[a] = min(price[a], price[a - 1] * 2);
    }

    ll ans = 5e18;
    while(L < 2e10){
        ans = min(ans, get_price(L));
        L += L & -L;
    }
    cout << ans;
}
