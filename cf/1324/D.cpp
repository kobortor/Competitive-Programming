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

    for (int &vi : v) cin >> vi;

    for (int &vi : v) {
        int x;
        cin >> x;
        vi -= x;
    }
    
    sort(allof(v));

    ll ans = 0;

    for (int i = 0, j = n; i < n; i++) {
        while (j != 0 && v[i] + v[j - 1] > 0) {
            j--;
        }

        ans += n - max(i + 1, j);
    }

    cout << ans;
}
