#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pii> pubs(n);
    for (int i = 0; i < n; i++) cin >> pubs[i].first;
    for (int i = 0; i < n; i++) cin >> pubs[i].second;

    sort(allof(pubs));
    reverse(allof(pubs));

    priority_queue<int> bads;

    int idx = 0;
    ll ans = 0;
    ll cur_cost = 0;

    while (!pubs.empty() || !bads.empty()) {
        if (bads.empty()) {
            idx = pubs.back().first;
        }

        while (!pubs.empty() && pubs.back().first == idx) {
            cur_cost += pubs.back().second;
            bads.push(pubs.back().second);
            pubs.pop_back();
        }

        if (!bads.empty()) {
            cur_cost -= bads.top();
            bads.pop();
        }

        ans += cur_cost;
        idx++;
    }

    cout << ans;
}
