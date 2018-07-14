#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

const int MAXN = 1e6 + 6;

ll N;
ll pow2[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pow2[0] = 1;
    for(int a = 1; a < MAXN; a++){
        pow2[a] = (pow2[a - 1] * 2) % mod;
    }

    cin >> N;

    ll ans = 0;

    ll tot = 0;
    for(int a = 1; a <= N; a++){
        ll x;
        cin >> x;

        x += tot;
        x %= mod;
        tot = x;

        ans += x * pow2[N - a];
        ans %= mod;

        if(N - a - 2 >= 0){
            ans += x * (N - a - 1) % mod * pow2[N - a - 2];
            ans %= mod;
        }
    }

    cout << ans;
}
