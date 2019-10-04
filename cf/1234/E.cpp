#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

ll ans[MAXN];
ll diff[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> xs(m);
    for (ll &x : xs) cin >> x;

    for (int a = 1; a < m; a++) {
        ll prv = xs[a - 1];
        ll nxt = xs[a];

        if (prv == nxt) continue;

        if (prv > nxt) swap (prv, nxt);

        ll init_val = nxt - prv;
        diff[1] += init_val;
        diff[prv] -= init_val;

        ans[prv] += nxt - 1;

        diff[prv + 1] += init_val - 1;
        diff[nxt] -= init_val - 1;

        ans[nxt] += prv;

        diff[nxt + 1] += init_val;
    }

    for (int a = 1; a <= n; a++) {
        diff[a] += diff[a - 1];
        ans[a] += diff[a];
    }

    for (int a = 1; a <= n; a++) {
        cout << ans[a] << " ";
    }
}
