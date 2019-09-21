#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
int lft[MAXN], rht[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    s = "$" + s;
    t = "$" + t;

    for (int a = 1, b = 1; a <= n; a++) {
        if (b <= m && s[a] == t[b]) {
            b++;
        }
        lft[a] = b - 1;
    }

    rht[n + 1] = m;
    for (int a = n, b = m; a >= 1; a--) {
        if (b >= 1 && s[a] == t[b]) {
            b--;
        }
        rht[a] = b;
    }

    int ans = 0;
    for (int a = 0, b = 1; a <= n; a++) {
        while (b <= n && lft[a] >= rht[b + 1]) {
            b++;
        }
        if (lft[a] >= rht[b]) {
            ans = max(ans, b - a - 1);
        }
    }

    cout << ans;
}
