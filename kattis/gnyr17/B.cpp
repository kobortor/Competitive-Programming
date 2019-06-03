#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int P;
    cin >> P;
    while (P--) {
        int tc, b, n;
        cin >> tc >> b >> n;

        int ans = 0;
        while (n) {
            int div = n / b;
            int mod = n % b;

            ans += mod * mod;
            n = div;
        }

        cout << tc << " " << ans << "\n";
    }
}
