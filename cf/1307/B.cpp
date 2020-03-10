#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int &ai : a) {
            cin >> ai;
        }

        int mx = *max_element(allof(a));

        int ans = max(2, (x + mx - 1) / mx);
        for (int ai : a) {
            if (x >= ai && (x - ai) % mx == 0) {
                ans = min(ans, (x - ai + mx - 1) / mx + 1);
            }
        }

        cout << ans << "\n";
    }
}
