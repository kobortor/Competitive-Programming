#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
ll vis[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(vis, -1, sizeof vis);

    ll A, alpha, beta, gamma, M, k;
    cin >> A >> alpha >> beta >> gamma >> M >> k;

    ll prv = A;
    ll step = 1;
    while (k--) {
        ll cur = (alpha * prv * prv + beta * prv + gamma) % M;
        if (vis[cur] == -1) {
            vis[cur] = step;
        } else {
            k %= step - vis[cur];
        }
        step++;
        prv = cur;
    }

    cout << prv;
}
