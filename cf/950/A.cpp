#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int L, R, A;
    cin >> L >> R >> A;

    int mn = min(L, R);
    L -= mn;
    R -= mn;

    int ans = mn * 2;

    if (A <= max(L, R)) {
        ans += A * 2;
    } else {
        ans += 2 * max(L, R);
        A -= max(L, R);
        ans += A / 2 * 2;
    }
    cout << ans;
}
