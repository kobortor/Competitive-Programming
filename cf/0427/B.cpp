#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, t, c;
    cin >> n >> t >> c;

    int ans = 0;
    int cnt = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x > t) {
            cnt = 0;
        } else {
            cnt++;
            if (cnt >= c) ans++;
        }
    }

    cout << ans;
}
