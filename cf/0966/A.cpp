#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, M, Cl, Ce, V, Q;

set<ll> stair, eleva;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Cl >> Ce >> V;

    while(Cl--){
        ll x;
        cin >> x;
        stair.insert(x);
    }
    while(Ce--){
        ll x;
        cin >> x;
        eleva.insert(x);
    }

    cin >> Q;
    while(Q--){
        ll xi, yi, xf, yf;
        cin >> xi >> yi >> xf >> yf;
        if(xi == xf){
            cout << abs(yi - yf) << "\n";
        } else {
            ll ans = 1e18;
            auto iter = stair.lower_bound(yi);
            if(iter != stair.end()){
                ans = min(ans, abs(xf - xi) + abs(yi - *iter) + abs(yf - *iter));
            }
            if(iter != stair.begin()){
                iter--;
                ans = min(ans, abs(xf - xi) + abs(yi - *iter) + abs(yf - *iter));
            }

            iter = eleva.lower_bound(yi);
            if(iter != eleva.end()){
                ans = min(ans, (abs(xf - xi) + V - 1) / V + abs(yi - *iter) + abs(yf - *iter));
            }
            if(iter != eleva.begin()){
                iter--;
                ans = min(ans, (abs(xf - xi) + V - 1) / V + abs(yi - *iter) + abs(yf - *iter));
            }
            cout << ans << "\n";
        }
    }
}
