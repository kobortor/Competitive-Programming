#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a, b;
    cin >> a >> b;

    ll ans = 1;
    for (int i = 1; i <= min(a, b); i++) {
        ans *= i;
    }

    cout << ans;
}
