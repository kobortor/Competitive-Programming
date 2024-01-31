#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 600600;
const ll pow3_11 = 177147;
const ll pow3_12 = 531441;

ll pow3[12];
vector<ll> g[MAXN];

bool vis[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    pow3[0] = 1;
    for (int i = 1; i < 12; i++) {
        pow3[i] = pow3[i - 1] * 3;
    }

    for (int i = 0; i < pow3_12; i++) {
        // connect to another one while masking
        for (int j = 0; j < 12; j++) {
            ll dig = i / pow3[j] % 3;
            if (dig == 2) continue;

            ll nxt = i + pow3[j];
            g[i].push_back(nxt);
        }
    }

    int n;
    cin >> n;

    ll end_pos;

    vector<ll> S(n);
    for (ll &Sn : S) {
        cin >> Sn;

        for (int i = 0; i < 12; i++) {
            ll cdig = (Sn / pow3[i]) % 3;

            for (int j = 0; j < cdig; j++) {
                ll cv = Sn + (pow3[i] * (j - cdig));
                g[Sn].push_back(cv);
            }
        }
    }

    queue<ll> q;

    vis[S[0]] = true;
    q.push(S[0]);
    while (!q.empty()) {
        ll fr = q.front();
        q.pop();

        for (ll p : g[fr]) {
            if (!vis[p]) {
                vis[p] = true;
                q.push(p);
            }
        }
    }

    bool good = vis[S.back()];
    if (good) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
