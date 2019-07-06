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
    for (int &i : v) cin >> i;

    sort(allof(v));

    int ans = 0;
    for (int a = 0; a < n; a += 2) {
        ans += v[a + 1] - v[a];
    }

    cout << ans;
}
