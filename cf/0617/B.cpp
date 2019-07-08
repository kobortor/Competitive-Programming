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

    ll ans = 1;
    int prv = -1;
    for (int a = 0; a < n; a++) {
        int x;
        cin >> x;
        if (x == 1) {
            if (prv != -1) {
                ans *= a - prv;
            }

            prv = a;
        }
    }

    if (prv == -1) cout << 0;
    else cout << ans;
}
