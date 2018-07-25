#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

ll N, X;

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

map<ll, ll> cnt;
ll arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> X;

    ll tot = 0;
    ll mn = 1e18;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        tot += arr[a];
    }

    for(int a = 1; a <= N; a++){
        cnt[tot - arr[a]]++;
        mn = min(mn, tot - arr[a]);
    }

    while(cnt[mn] % X == 0){
        cnt[mn + 1] += cnt[mn] / X;
        mn++;
    }

    cout << qpow(X, min(mn, tot));
}
