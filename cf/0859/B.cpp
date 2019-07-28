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
    
    int ans = 1e9;
    for (int a = 1; a <= n; a++) {
        ans = min(ans, 2 * (a + (n + a - 1) / a));
    }
    cout << ans;
}
