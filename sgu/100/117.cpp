#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int qpow (int n, int m, int k) {
    int ans = 1;
    while (m) {
        if (m & 1) ans = ans * n % k;

        m /= 2;
        n = n * n % k;
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;

    while (n--) {
        int x;
        cin >> x;

        ans += !qpow(x, m, k);
    }

    cout << ans;
}
