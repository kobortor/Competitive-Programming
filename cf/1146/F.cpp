#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const ll mod = 998244353;

ll pow2[MAXN];
ll N;
vector<int> adj[MAXN];

ll dp0[MAXN]; //cannot continue up
ll dp1[MAXN]; //a single color going up
ll dp2[MAXN]; //2 colors going up

ll qpow(ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % mod;

        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
ll inv(ll x) {
    return qpow(x, mod - 2);
}

void dfs(int pos) {
    if(adj[pos].empty()){
        dp0[pos] = 0;
        dp1[pos] = 0;
        dp2[pos] = 1;
        return;
    }

    ll d0 = 1, d1 = 0, d2 = 0;
    for (int i : adj[pos]) {
        dfs (i);
        //ignore everything
        ll t0 = d0 * (dp0[i] + dp2[i]) % mod; 

        //take 1, or ignore
        ll t1 = (d0 * (dp1[i] + dp2[i]) + d1 * (dp0[i] + dp2[i])) % mod;

        //continue from 1, continue from 2, or ignore
        ll t2 = (d1 * (dp1[i] + dp2[i]) + d2 * (dp1[i] + dp2[i]) + d2 * (dp0[i] + dp2[i])) % mod;

        d0 = t0;
        d1 = t1;
        d2 = t2;
    }

    dp0[pos] = d0;
    dp1[pos] = d1;
    dp2[pos] = d2;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pow2[0] = 1;
    for (int a = 1; a < MAXN; a++) {
        pow2[a] = pow2[a - 1] * 2 % mod;
    }

    cin >> N;
    for (int a = 2; a <= N; a++) {
        int par;
        cin >> par;
        adj[par].push_back(a);
    }

    dfs(1);

    cout << (dp0[1] + dp2[1]) % mod;
}
