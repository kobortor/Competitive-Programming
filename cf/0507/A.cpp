#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<pii> v(n);
    for (int a = 0; a < n; a++) {
        cin >> v[a].first;
        v[a].second = a + 1;
    }
    sort(allof(v));

    int ans = 0;
    while (ans < n && v[ans].first <= k) {
        k -= v[ans++].first;
    }

    cout << ans << "\n";
    for (int a = 0; a < ans; a++) {
        cout << v[a].second << " ";
    }
}
