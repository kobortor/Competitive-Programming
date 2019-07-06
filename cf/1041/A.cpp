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

    int mx = -1e9, mn = 1e9;
    for (int a = 0, i; a < n; a++) {
        cin >> i;
        mn = min(mn, i);
        mx = max(mx, i);
    }

    cout << mx - mn + 1 - n;
}
