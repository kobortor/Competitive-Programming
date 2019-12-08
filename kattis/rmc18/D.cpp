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

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] >= n - i) {
            ans = n - i;
        }
    }
    cout << ans;
}
