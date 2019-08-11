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

    int ans = 0;
    int cur = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cur += b - a;

        ans = max(ans, cur);
    }
    cout << ans;
}
