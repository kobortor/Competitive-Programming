#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int DIG = 19;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("exact.in", "r", stdin);
    freopen("exact.out", "w", stdout);

    ll x, n; cin >> x >> n;

    vector<vector<pair<ll,ll>>> pcks(DIG);

    for (int i = 0; i < n; i++) {
        ll k, q; cin >> k >> q;
        for (int j = 0; j < k; j++)
            q *= 10;
        pcks[k].push_back({q, i + 1});
    }

    ll cdig;
    ll cp = 1;
    set<pair<ll,ll>> curr;
    
    vector<ll> ans;
    ll hv = 0;

    for (int i = 0; i < DIG; i++) {
        cdig = (x % 10);
        x /= 10;

        for (auto p : pcks[i])
            curr.insert(p);

        while (hv < cdig * cp && curr.size()) {
            
            auto [val, ind] = *curr.rbegin();
            curr.erase({val, ind});

            ans.push_back(ind);

            hv += val;

        }

        if (hv < cdig * cp) {
            cout << "-1\n";
            return 0;
        }

        hv -= cdig * cp;
        cp *= 10;

    }    


    cout << ans.size() << "\n";
    for (ll i : ans)
        cout << i << " ";
    cout << "\n";

}
