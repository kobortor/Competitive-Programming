#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N;
string words[MAXN];
int req[MAXN];
vector<pii> adj[MAXN];

void testcase() {
    cin >> N;
    for (int a = 0; a < N; a++) {
        cin >> words[a];
        reverse(allof(words[a]));

        adj[a].clear();
        req[a] = 999999;
    }

    priority_queue<pair<int, pii>> edges;
    for (int a = 0; a < N; a++) {
        for (int b = a + 1; b < N; b++) {
            int match = 0;
            while (match < (int)words[a].size() && match < (int)words[b].size() && words[a][match] == words[b][match]) {
                match++;
            }
            edges.push({match, {a, b}});
            adj[a].push_back({b, match});
            adj[b].push_back({a, match});
        }
    }

    int ans = 0;
    while (!edges.empty()) {
        auto au = edges.top();
        edges.pop();

        int origmatch = au.first;
        int u = au.second.first;
        int v = au.second.second;
        int match = min(origmatch, min(req[u], req[v]));
        if (match <= 0) {
            continue;
        }
        if (match != origmatch) {
            edges.push({match, {u, v}});
            continue;
        }

        req[u] = 0;
        req[v] = 0;

        for (pii p : adj[u]) {
            if (match <= p.second) {
                req[p.first] = min(req[p.first], match - 1);
            }
        }

        for (pii p : adj[v]) {
            if (match <= p.second) {
                req[p.first] = min(req[p.first], match - 1);
            }
        }

        ans += 2;
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    for (int a = 1; a <= T; a++) {
        cout << "Case #" << a << ": ";
        testcase();
    }
}
