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

    int mn = *min_element(allof(v));
    int mx = *max_element(allof(v));

    ll cn = count(allof(v), mn);
    ll cx = count(allof(v), mx);

    cout << mx - mn << " ";
    if (mx == mn) {
        cout << cx * (cx - 1) / 2;
    } else {
        cout << cx * cn;
    }
}
