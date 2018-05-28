#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;
const int MAXH = 1e6 + 6;
const int mod = 1e9 + 7;

int N, K;
int tall[MAXN];

int fact[MAXH];
int qpow(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1){
            ans = (ll)ans * x % mod;
        }

        y >>= 1;
        x = (ll)x * x % mod;
    }
    return ans;
}

int nck(int n, int k){
    if(k > n){
        return 0;
    }
    int val = (ll)fact[n] * qpow(fact[k], mod - 2) % mod * qpow(fact[n - k], mod - 2) % mod;
    return val;
}

array<int, MAXN> solve(int l, int r, int ht){
    if(r < l){
        array<int, MAXN> ans;
        fill(allof(ans), 0);
        ans[0] = 1;
        return ans;
    }

    if(l == r){
        array<int, MAXN> ans;
        fill(allof(ans), 0);
        ans[0] = 1;
        ans[1] = tall[l] - ht;
        return ans;
    }

    int minid = min_element(tall + l, tall + r + 1) - tall;
    array<int, MAXN> lft = solve(l, minid - 1, tall[minid]);
    array<int, MAXN> rht = solve(minid + 1, r, tall[minid]);
    
    array<int, MAXN> comb;
    fill(allof(comb), 0);

    for(int a = 0; a <= (int)r - l; a++){
        for(int b = 0; b <= a; b++){
            comb[a] += (ll)lft[b] * rht[a-b] % mod;
            comb[a] %= mod;
        }
    }

    int remainht = tall[minid] - ht;
    int remainwid = r - l + 1;
    
    for(int a = r - l + 1; a >= 0; a--){
        for(int b = 0; b < a; b++){
            comb[a] += (ll)comb[b] * nck(remainht, a - b) % mod * nck(remainwid - b, a - b) % mod * fact[a - b] % mod;
            comb[a] %= mod;
        }
    }
    return comb;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fact[0] = 1;
    for(int a = 1; a < MAXH; a++){
        fact[a] = (ll)fact[a-1] * a % mod;
    }

    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        cin >> tall[a];
    }

    cout << solve(1, N, 0)[K];
}
