#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll P, K;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<ll> ans;

    cin >> P >> K;

    ll base = 1;
    while(P){
        ll diff = (base == 1 ? P % K : (K - P % K) % K);
        if(base == 1){
            P -= diff;
        } else {
            P += diff;
        }
        base *= -1;
        P /= K;
        if(diff >= K){
            cout << -1;
            return 0;
        }
        ans.push_back(diff);
    }
    cout << ans.size() << "\n";
    for(ll x : ans){
        cout << x << " ";
    }

}
