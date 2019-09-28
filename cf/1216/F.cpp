#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

// <cost, valid through>
vector<pll> jumps[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    for (int a = 0; a < n; a++) {
        jumps[a].push_back({a + 1, a + 1});
        if (s[a] == '1') {
            int l = max(1, a + 1 - k);
            int r = min(n, a + 1 + k);

            jumps[l - 1].push_back({a + 1, r});
        }
    }

    // <cost, valid through>
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    for (int a = 0; a < n; a++) {
        ll cost = pq.top().first;
        for (pll p : jumps[a]) {
            pq.push({cost + p.first, p.second});
        }

        while (!pq.empty() && pq.top().second <= a) {
            pq.pop();
        }
    }

    cout << pq.top().first;
}
