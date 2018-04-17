#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll Q;

ll layer(ll x){
    ll ans = 0;
    while(x > 1){
        ans++;
        x >>= 1;
    }
    return ans;
}

ll cycle(ll val, ll mv, ll lay){
    val -= (1ll << lay);
    val += mv;
    val %= (1ll << lay);
    if(val < 0){
        val += 1ll << lay;
    }
    val += 1ll << lay;
    return val;
}

ll shift[64];
ll idshift[64];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> Q;
    while(Q--){
        int tp;
        cin >> tp;
        if(tp == 1){
            ll X, K;
            cin >> X >> K;
            
            ll lay = layer(X);
            idshift[lay] += K;
            shift[lay] -= K;
        } else if (tp == 2){
            ll X, K;
            cin >> X >> K;           

            ll lay = layer(X);
            for(ll a = 0; a + lay < 64; a++){
                idshift[a + lay] += K * (1ll << a);
                shift[a + lay] -= K * (1ll << a);
            }
        } else {
            ll X;
            cin >> X;
            ll lay = layer(X);

            X = cycle(X, idshift[lay], lay);

            while(X) {
                cout << cycle(X, shift[lay], lay) << " ";
                X >>= 1;
                lay--;
            }
            cout << "\n";
        }
    }
}
