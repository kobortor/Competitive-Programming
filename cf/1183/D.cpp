#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> v;
        while (n--) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        sort(allof(v));

        vector<int> sizes;

        int idx = 0;
        while (idx < (int)v.size()) {
            int nxt = idx + 1;
            while (nxt < (int)v.size() && v[nxt] == v[idx]) {
                nxt++;
            }

            sizes.push_back(nxt - idx);
            idx = nxt;
        }

        sizes.push_back(1e9);
        sort(allof(sizes), greater<int>());

        int ans = 0;
        for (int a = 1; a < (int)sizes.size(); a++) {
            sizes[a] = min(sizes[a], sizes[a - 1] - 1);
            if (sizes[a] <= 0) break;
            ans += sizes[a];
        }

        cout << ans << "\n";
    }

}
