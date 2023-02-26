#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define f first
#define s second

const int MN = 1000005;

int t, n, k, s, u, die[MN], ans[MN], tim[MN];
pii e[MN];
vector<pii> a[MN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= k; i++) {
            cin >> e[i].f >> e[i].s;
            a[e[i].f].push_back({e[i].s, i});
        }
        priority_queue<pii> q;
        cin >> s;
        for (int i = 1; i <= s; i++) cin >> u, die[u] = 1;
        for (int i = 1; i <= n; i++) {
            if (!die[i]) tim[i] = 0x3f3f3f3f, q.push({tim[i], i});
        }
        while (q.size()) {
            pii cur = q.top(); q.pop();
            if (tim[cur.s] < cur.f) continue;
            for (pii nxt : a[cur.s]) {
                if (nxt.s > tim[cur.s]) continue;
                if (tim[nxt.f] < nxt.s) {
                    tim[nxt.f] = nxt.s;
                    q.push({tim[nxt.f], nxt.f});
                }
            }
        }
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            if (die[i] && !tim[i]) ok = 0;
            if (die[i]) ans[tim[i]] = 1;
        }
        if (!ok) printf("NIE\n");
        else {
            printf("TAK\n");
            for (int i = 1; i <= k; i++) {
                if (ans[i]) printf("T");
                else printf("N");
            }
            printf("\n");
        }
        for (int i = 1; i <= n; i++) die[i] = 0, tim[i] = 0, a[i].clear();
        for (int i = 1; i <= k; i++) ans[i] = 0;
    }
}
