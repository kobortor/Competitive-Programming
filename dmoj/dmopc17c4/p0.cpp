#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll X1, X2, X3;
ll Y1, Y2, Y3;

ll sq(ll a, ll b){
    return a * a + b * b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> X1 >> Y1;
    cin >> X2 >> Y2;
    cin >> X3 >> Y3;

    ll ans = sq(X1 - X2, Y1 - Y2);
    ans = min(ans, sq(X1 - X3, Y1 - Y3));
    ans = min(ans, sq(X2 - X3, Y2 - Y3));

    cout << ans;
}
