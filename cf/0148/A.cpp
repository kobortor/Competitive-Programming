#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    int ans = 0;
    for (int a = 1; a <= d; a++) {
        if (a % k == 0 || a % l == 0 || a % m == 0 || a % n == 0) {
            ans++;
        }
    }

    cout << ans;
}
