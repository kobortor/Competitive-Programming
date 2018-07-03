#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, Q;
ll cnt[32];
ll tmp[32];

ll lg2(ll x){
    ll ans = 0;
    while(x != 1){
        ans++;
        x /= 2;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;
    while(N--){
        ll x;
        cin >> x;
        cnt[lg2(x)]++;
    }

    while(Q--){
        memcpy(tmp, cnt, sizeof cnt);

        ll x;
        cin >> x;

        ll ans = 0;
        while(x){
            ll top = x & -x;
            ll power = lg2(top);
            ll tot = top;

            for(int a = power; a >= 0; a--){
                if((tmp[a] << a) >= tot){
                    tmp[a] -= tot >> a;
                    ans += tot >> a;
                    tot = 0;
                    break;
                } else {
                    tot -= tmp[a] << a;
                    ans += tmp[a];
                    tmp[a] = 0;
                }
            }

            if(tot != 0){
                ans = -1;
                break;
            }

            x -= top;
        }

        cout << ans << "\n";
    }
}
