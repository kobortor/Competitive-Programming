#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int n, m, k;

bool vis[MAXN];
vector<int> adj[MAXN];

void euler_tour(int pos, vector<int> &result) {
    result.push_back(pos);
    vis[pos] = true;

    for (int i : adj[pos]) {
        if (!vis[i]) {
            euler_tour(i, result);
            result.push_back(pos);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> k;

    while (m--) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> tour;
    euler_tour(1, tour);

    int len = (2 * n + k - 1) / k;

    for (int t = 0; t < k; t++) {
        vector<int> visits;
        for (int i = 0; i < len && t * len + i < (int)tour.size(); i++) {
            visits.push_back(tour[t * len + i]);
        }

        if (visits.empty()) {
            cout << "1 1\n";
        } else {
            cout << visits.size();

            for (int i : visits) {
                cout << " " << i;
            }

            cout << "\n";
        }
    }
}
