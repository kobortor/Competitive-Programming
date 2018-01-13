#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN =  1e6 + 6;
const ll mod = 1e9 + 7;

ll fact[MAXN];

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1){
            ans = ans * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fact[0] = 1;
    for(int a = 1; a < MAXN; a++){
        fact[a] = fact[a - 1] * a % mod;
    }

    int N, A, B, D;
    while(cin >> N >> A >> B >> D){
        cout << fact[N] % mod * qpow(fact[A], mod - 2) % mod * qpow(fact[N - A], mod - 2) % mod *
        qpow(   fact[B] % mod * qpow(fact[D], mod - 2) % mod * qpow(fact[B - D], mod - 2) % mod, A) % mod << endl;
    }
}
