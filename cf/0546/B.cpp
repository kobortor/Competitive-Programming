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

    vector<int> v(n);
    for (int &vi : v) {
        cin >> vi;
    }

    sort(allof(v));

    int low = -100;
    int ans = 0;

    for (int vi : v) {
        low = max(low + 1, vi);
        ans += low - vi;
    }

    cout << ans;
}
