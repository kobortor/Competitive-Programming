#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int r, d;
    cin >> r >> d;

    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        int xi, yi, ri;
        cin >> xi >> yi >> ri;
        if ((r - d + ri) * (r - d + ri) <= xi * xi + yi * yi &&
            (r - ri) * (r - ri) >= xi * xi + yi * yi) {
            ans++;
        }
    }

    cout << ans;
}
