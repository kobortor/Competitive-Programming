#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

const ll mod = 1e9 + 7;

ll fact[MAXN];
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

ll nck(ll n, ll k){
    return fact[n] * qpow(fact[k], mod - 2) % mod * qpow(fact[n - k], mod - 2) % mod;
}

string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fact[0] = 1;
    for(int a = 1; a < MAXN; a++){
        fact[a] = fact[a - 1] * a % mod;
    }

    cin >> str;
    
    int NL = 0, NR = 0;
    for(char c : str){
        if(c == ')'){
            NR++;
        }
    }

    ll ans = 0;
    for(char c : str){
        if(c == '('){
            NL++;
            if(NR != 0){
                ans += nck(NL - 1 + NR, NR - 1);
                ans %= mod;
            }
        } else {
            NR--;
        }
    }

    cout << ans;
}
