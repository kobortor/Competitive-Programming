#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

vector<int> adj[MAXN];

int euler;
int view[MAXN];
pii range[MAXN];
void tour(int pos, int par) {
    range[pos] = {100000000, -1};
    bool leaf = true;
    view[pos] = 1;
    for (int i : adj[pos]) {
        if (i == par) continue;

        leaf = false;
        tour(i, pos);
        range[pos].first = min(range[pos].first, range[i].first);
        range[pos].second = max(range[pos].second, range[i].second);
        view[pos] += view[i];
    }

    if (leaf) {
        range[pos] = {euler, euler};
        euler++;
    }
    // cout << pos << " has range " << range[pos].first << " " << range[pos].second << " and weight " << view[pos] << endl;
}

bool good(vector<pii> &v) {
    // cout << "Foudn range\n";
    // for (int i = 0; i + 1 < (int)v.size(); i++) {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    sort(allof(v));
    if (v[0].first != 1) {
        return false;
    }
    if (v.back().second != euler - 1) {
        return false;
    }
    for (int i = 0; i + 1 < (int)v.size(); i++) {
        if (v[i].second + 1 != v[i + 1].first) {
            return false;
        }
    }
    return true;
}

void testcase() {
    int n;
    cin >> n;

    euler = 1;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    map<int, vector<pii>> ranges;

    tour(1, -1);
    for (int i = 1; i <= n; i++) {
        ranges[view[i]].push_back(range[i]);
    }

    vector<int> soln;
    for (auto [x, v] : ranges) {
        if (good(v)) {
            soln.push_back(x);
        }
    }

    cout << soln.size() << "\n";
    for (int i : soln) {
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int z;
    cin >> z;
    while (z--) {
        testcase();
    }
}
