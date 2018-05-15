#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

const int MAXN = 2e6 + 6;

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

void testcase(){
    ll B, G;
    cin >> B >> G;

    //cout << "Working on " << B << " + " << G << endl;
    if(G == 1){
        cout << 0 << endl;
        return;
    }

    ll ans = fact[B + G];
    for(ll gap = 0;; gap += 2){
        ll block = (G - 1) * gap;
        if(block > B){
            break;
        }

        ans -= fact[G] * fact[B] % mod * (B - block + 1) % mod;
        ans %= mod;
        if(ans < 0){
            ans += mod;
        }
    }
    ans %= mod;
    if(ans < 0){
        ans += mod;
    }

    cout << ans << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    assert(freopen("DATA12.txt", "r", stdin));

    fact[0] = 1;
    for(int a = 1; a < MAXN; a++){
        fact[a] = fact[a-1] * a % mod;
    }

    const int NTEST = 10;
    for(int a = 1; a <= NTEST; a++){
        testcase();
    }
}
