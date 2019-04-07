#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;

map<string, int> dist;
map<string, vector<pair<string, int>>> adj;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for (int a = 0; a < N; a++) {
        string s;
        cin >> s;
        dist[s] = 99999;
    }

    while (M--) {
        string a, b;
        int c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dist["English"] = 0;

    vector<string> cur;
    cur.push_back("English");
    int added = 0, ans = 0;

    while (!cur.empty()) {
        int curdist = dist[cur[0]];
        vector<pair<int, string>> nxt;
        for (string s : cur) {
            for (pair<string, int> p : adj[s]) {
                if (dist[p.first] == 99999) {
                    nxt.push_back({p.second, p.first});
                }
            }
        }

        cur.clear();
        sort(allof(nxt));
        for (pair<int, string> p : nxt) {
            if (dist[p.second] == 99999) {
                dist[p.second] = curdist + 1;
                added++;
                ans += p.first;
                cur.push_back(p.second);
            }
        }
    }

    if (added == N) {
        cout << ans << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
