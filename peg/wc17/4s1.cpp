#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, M, K;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;
    ll ans = M - 1;
    ans += (N - 1) * (1 + min(M - 1, K));
    K -= min(M - 1, K);

    ans -= K;
    cout << ans;
}
