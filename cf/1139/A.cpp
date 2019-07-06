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
    string s;
    cin >> n >> s;

    ll ans = 0;
    for (int a = 0; a < n; a++) {
        if ((s[a] - '0') % 2 == 0) {
            ans += a + 1;
        }
    }

    cout << ans;
}
