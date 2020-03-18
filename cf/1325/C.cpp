#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pii> edges(n - 1);
    for (pii &p : edges) {
        cin >> p.first >> p.second;
        ans[p.first]++;
        ans[p.second]++;
    }

    int idx = 0;
    int mx = max_element(ans, ans + MAXN) - ans;
    
    for (int i = 0; i < (int)edges.size(); i++) {
        if (edges[i].first == mx || edges[i].second == mx) {
            ans[i] = idx++;
        }
    }

    for (int i = 0; i < (int)edges.size(); i++) {
        if (!(edges[i].first == mx || edges[i].second == mx)) {
            ans[i] = idx++;
        }
    }

    for (int i = 0; i < (int)edges.size(); i++) {
        cout << ans[i] << "\n";
    }
}
