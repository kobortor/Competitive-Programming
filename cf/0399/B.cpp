#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;
ll cost[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    /*
     * cost(0) = 1
     * cost(n + 1) = 1 + cost(1) + cost(2) + ... + cost(n)
     */

    for (int a = 0; a < MAXN; a++) {
        cost[a] = 1;
        for (int b = 0; b < a; b++) cost[a] += cost[b];
    }

    int n;
    string s;
    cin >> n >> s;

    ll ans = 0;
    for (int a = 0; a < n; a++) {
        if (s[a] == 'B') ans += cost[a];
    }

    cout << ans;
}
