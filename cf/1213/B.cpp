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
        int n;
        cin >> n;

        vector<int> v(n);
        for (int &i : v) cin >> i;

        reverse(allof(v));

        int ans = 0;
        int min_price = 1e9;
        for (int i : v) {
            if (i > min_price) ans++;

            min_price = min(min_price, i);
        }

        cout << ans << endl;
    }
}
