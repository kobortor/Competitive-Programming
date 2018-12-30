#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

const int MAXN = 1e6 + 6;

int N;

ll fact[MAXN];
ll rfac[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    fact[0] = 1;

    for(int a = 1; a <= N; a++){
        fact[a] = fact[a - 1] * a % mod;
    }

    rfac[N + 1] = 1;
    for(int a = N; a >= 1; a--){
        rfac[a] = rfac[a + 1] * a % mod;
    }

    ll ans = 1;
    for(int a = 1; a <= N; a++){
        ans += (fact[a] - 1) * rfac[a + 1];
        ans %= mod;
    }
    cout << ans;
}
