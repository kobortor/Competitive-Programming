#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const ll mod = 1e9 + 7;

int N;
vector<int> adj[MAXN];
ll fact[MAXN];

ll sz[MAXN];

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y) {
        if(y & 1){
            ans = ans * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

ll dfs(int pos){
    ll ans = 1;
    sz[pos] = 1;
    map<int, int> sizes;
    for(int i : adj[pos]){
        ans = ans * dfs(i) % mod;
        sz[pos] += sz[i];
        sizes[sz[i]]++;
    }

    ans = ans * fact[adj[pos].size() + 1] % mod;
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fact[0] = 1;
    for(int a = 1; a < MAXN; a++){
        fact[a] = fact[a - 1] * a % mod;
    }

    cin >> N;
    for(int a = 1; a < N; a++){
        int x;
        cin >> x;
        adj[x].push_back(a);
    }
    cout << dfs(0);
}
