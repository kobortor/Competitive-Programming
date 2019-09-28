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

    vector<pii> v(n);
    for (int a = 0; a < n; a++) {
        cin >> v[a].first;
        v[a].second = a;
    }

    sort(allof(v));
    reverse(allof(v));
    vector<int> ans;

    int tot = 0;
    for (int a = 0; a < n; a++) {
        tot += v[a].first * a + 1;
    }

    cout << tot << "\n";
    for (pii p : v) cout << p.second + 1 << " ";
}
