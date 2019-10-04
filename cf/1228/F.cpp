#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int dist[MAXN];
int par[MAXN];
int sz[MAXN];
int N;

int getsize (int from, int to) {
    if (par[to] == from) {
        return sz[to];
    } else {
        return N - sz[from];
    }
}

void dfs1 (int pos) {
    sz[pos] = 1;
    for (int i : adj[pos]) {
        if (i != par[pos]) {
            par[i] = pos;
            dfs1(i);

            sz[pos] += sz[i];
        }
    }
}

bool ensure_full (int pos, int abv) {
    vector<int> children;
    for (int i : adj[pos]) {
        if (i != abv) {
            children.push_back(i);
        }
    }

    if (children.empty()) return true;

    if ((int)children.size() != 2) return false;

    int s0 = getsize(pos, children[0]);
    int s1 = getsize(pos, children[1]);

    if (s0 != s1) {
        return false;
    } else {
        return ensure_full(children[0], pos) && ensure_full(children[1], pos);
    }
}

int parent;
bool dfs2 (int pos, int abv) {
    vector<int> children;
    for (int i : adj[pos]) {
        if (i != abv) {
            children.push_back(i);
        }
    }

    if (children.empty()) {
        return true;
    } else if ((int)children.size() == 1) {
        parent = pos;
        return ensure_full(children[0], pos);
    } else if ((int)children.size() == 2) {
        int s0 = getsize(children[0], pos);
        int s1 = getsize(children[1], pos);
        
        if (abs(s0 - s1) != 1) return false;

        bool e0 = ensure_full(children[0], pos);
        bool e1 = ensure_full(children[1], pos);

        bool d0 = dfs2(children[0], pos);
        bool d1 = dfs2(children[1], pos);

        if (e0 && d1) return true;
        if (e1 && d0) return true;

        return false;
    } else if ((int)children.size() == 3) {
        int s0 = getsize(pos, children[0]);
        int s1 = getsize(pos, children[1]);
        int s2 = getsize(pos, children[2]);

        if (s0 == s1 && s1 == s2) {
            return false;
        }

        int mins = min(s0, min(s1, s2));
        int maxs = max(s0, max(s1, s2));

        if (mins * 2 + 1 != maxs) return false;
        if (s0 + s1 + s2 != 2 * maxs - 1) return false;
parent = pos;

        return  ensure_full(children[0], pos) &&
                ensure_full(children[1], pos) &&
                ensure_full(children[2], pos);
    } else {
        return false;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int _n;
    cin >> _n;

    N = (1 << _n) - 2;
    for (int a = 1; a <= N - 1; a++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    for (int a = 1; a <= N; a++) {
        if ((int)adj[a].size() == 1) {
            dist[a] = 1;
            q.push(a);
        }
    }

    while (!q.empty()) {
        int fr = q.front();
        q.pop();

        for (int i : adj[fr]) {
            if (dist[i] == 0) {
                dist[i] = dist[fr] + 1;
                q.push(i);
            }
        }
    }

    int maxdist = *max_element(dist, dist + MAXN);

    dfs1 (1);

    vector<int> ans;
    for (int a = 1; a <= N; a++) {
        if (dist[a] == maxdist && dfs2(a, -1)) {
            ans.push_back(parent);
        }
    }

    sort(allof(ans));
    ans.erase(unique(allof(ans)), ans.end());

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
}
