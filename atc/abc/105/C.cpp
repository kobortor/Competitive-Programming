#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string ans;

    ll num;
    cin >> num;

    if(num == 0){
        cout << 0;
        return 0;
    }

    for(ll a = 0; num; a++){
        if(num % (2ll << a)){
            ans += "1";
            if(a % 2){
                num += 1ll << a;
            } else {
                num -= 1ll << a;
            }
        } else {
            ans += "0";
        }
    }

    reverse(allof(ans));

    cout << ans;
}
