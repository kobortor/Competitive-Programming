#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int k;
    cin >> k;

    int ans = 0;
    while (k--) {
        int r;
        cin >> r;
        ans = max(ans, r - 25);
    }

    cout << ans;
}
