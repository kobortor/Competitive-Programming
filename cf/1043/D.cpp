#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int nxt[MAXN];
int ans[MAXN];

int recur(int pos) {
    if (ans[pos] != -1) {
        return ans[pos];
    }

    if (nxt[pos] == -1) {
        return ans[pos] = 1;
    } else {
        return ans[pos] = recur(nxt[pos]) + 1;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int a = 1; a <= m; a++) {
        int cur, prv;
        cin >> prv;

        for (int b = 2; b <= n; b++) {
            cin >> cur;
            if (nxt[prv] == 0) {
                nxt[prv] = cur;
            } else if (nxt[prv] != cur) {
                nxt[prv] = -1;
            }

            prv = cur;
        }

        nxt[prv] = -1;
    }

    memset(ans, -1, sizeof ans);

    ll tot = 0;
    for (int a = 1; a <= n; a++) {
        tot += recur(a);
    }

    cout << tot;
}
