#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    
    ll tot = 1;
    ll ans = 1;
    while (n--) {
        tot = tot * 27 % mod;
        ans = ans * 7 % mod;
    }

    cout << (tot - ans + mod) % mod;
}
