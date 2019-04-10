#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;

int N, M;

bool marked[MAXN];
int degree[MAXN];
vector<int> adj[MAXN];

bool vis[MAXN];
bool istree (int pos) {
    vis[pos] = true;

    int other = 0;
    for (int i : adj[pos]) {
        if (vis[i]) {
            other++;
        } else if (!istree(i)) {
            other = 9999999;
        }
    } 

    return other <= 1;
}

vector<pii> ans;
void leaves(int pos, int prv) {
    if ((int)adj[pos].size() == 1) {
        ans.push_back({pos, adj[pos][0]});
    }
    for (int i : adj[pos]) {
        if (i != prv) {
            leaves(i, pos);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;

        degree[u]++; degree[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    for (int a = 1; a <= N; a++) {
        if (degree[a] == 1) {
            marked[a] = true;
            q.push(a);
        }
    }

    while (!q.empty()) {
        int fr = q.front();
        q.pop();
        for (int i : adj[fr]) {
            if (!marked[i]) {
                degree[i]--;
                if (degree[i] == 1) {
                    marked[i] = true;
                    q.push(i);
                }
            }
        } 
    }

    for (int a = 1; a <= N; a++) {
        if (marked[a]) continue;

        for (int i : adj[a]) {
            if (marked[i]) {
                ans.push_back({a, i});
            }
        }
    }

    for (int a = 1; a <= N; a++) {
        if (!vis[a] && istree(a)) {
            leaves(a, -1);
        }
    }

    sort(allof(ans));
    cout << ans.size() << "\n";
    for (pii p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}
