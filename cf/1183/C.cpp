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
        ll k, n, a, b;
        cin >> k >> n >> a >> b;
        k--;

        int diff = a - b;

        if (k - b * n >= 0) {
            cout << min(n, (k - b * n) / diff) << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
