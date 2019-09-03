#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 50005;

int N, M;
vector<int> adj[MAXN];
set<pii> wts[MAXN];
int ans[MAXN];

int merge (set<pii> &s1, set<pii> &s2) {
    if (s1.size() < s2.size()) swap(s1, s2);

    int ans = INT_MAX;

    for (pii p : s2) {
        auto iter = s1.insert(p).first;
        if (iter != s1.begin()) {
            ans = min(ans, iter->first - prev(iter)->first);
        }

        if (next(iter) != s1.end()) {
            ans = min(ans, next(iter)->first - iter->first);
        }
    }

    return ans;
}

void dfs (int pos) {
    ans[pos] = INT_MAX;
    for (int i : adj[pos]) {
        dfs(i);

        ans[pos] = min(ans[pos], ans[i]);
        ans[pos] = min(ans[pos], merge(wts[pos], wts[i]));
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for (int a = 2; a <= N; a++) {
        int par;
        cin >> par;
        adj[par].push_back(a);
    }

    for (int a = N - M + 1; a <= N; a++) {
        int x;
        cin >> x;
        wts[a].insert({x, a});
    }

    dfs (1);

    for (int a = 1; a <= N - M; a++) {
        cout << ans[a] << " ";
    }
}
