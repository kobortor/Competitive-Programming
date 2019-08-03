#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;
const ll mod = 1e9 + 7;
set<char> letters[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    while (n--) {
        string s;
        cin >> s;
        for (int a = 0; a < m; a++) {
            letters[a].insert(s[a]);
        }
    }

    ll ans = 1;
    for (int a = 0; a < m; a++) {
        ans = ans * (ll)letters[a].size() % mod;
    }

    cout << ans;
}
