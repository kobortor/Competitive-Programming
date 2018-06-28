#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 9; //why even

ll N, K, A, B;

string str;

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1){
            ans = ans * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B >> K;
    cin >> str;

    ll tmp = 0;
    for(int a = 0; a < (int)str.size(); a++){
        if(str[a] == '+'){
            tmp += qpow(A, N - a) * qpow(B, a) % mod;
            tmp %= mod;
        } else {
            tmp -= qpow(A, N - a) * qpow(B, a) % mod;
            tmp %= mod;
            if(tmp < 0){
                tmp += mod;
            }
        }
    }

    ll W = (N + 1) / K;

    if(A == 1 && B == 1){
        cout << tmp * W % mod;
        return 0;
    }

    ll mult = qpow(qpow(A, K), mod - 2) * qpow(B, K) % mod;

    ll ans = 0;
    if(mult != 1) {
        ans = (qpow(mult, W) - 1) * qpow(mult - 1, mod - 2) % mod;
    } else {
        ans = W % mod;
    }
    if(ans < 0){
        ans += mod;
    }

    cout << ans * tmp % mod;
}
