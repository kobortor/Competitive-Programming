#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 20005;
const ll mod = 1e9 + 7;
const ll seed = 961748941;

ll N, K;
ll arr[MAXN];

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}

bool check(int len){
    ll hsh = 0;

    unordered_map<ll, ll> ump;
    for(int a = 1; a <= N; a++){
        hsh = (hsh * seed + arr[a]) % mod;
        if(a >= len){
            hsh -= (qpow(seed, len) * arr[a - len]) % mod;
            if(hsh < 0){
                hsh += mod;
            }
            ump[hsh]++;
        }
    }

    for(pll p : ump){
        if(p.second >= K){
            return true;
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    int lo = 1, hi = N;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo - 1 << "\n";
}
