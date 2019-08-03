#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int w, h;
    cin >> w >> h;
    if (w > h) swap(w, h);

    ll ans = 1;
    for (int a = 0; a < w; a++) {
        ans = ans * 4 % mod;
    }
    for (int a = w; a < h; a++) {
        ans = ans * 2 % mod;
    }
    cout << ans;
}
