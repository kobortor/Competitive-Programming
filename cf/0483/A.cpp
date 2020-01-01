#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll l, r;
    cin >> l >> r;

    if (l % 2) l++;

    if (r - l <= 1) cout << -1;
    else cout << l << " " << l + 1 << " " << l + 2;
}
