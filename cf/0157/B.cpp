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

    v.push_back(0);
    sort(allof(v));

    int ans = 0;
    for (int a = v.size() - 1; a >= 1; a -= 2) {
        ans += v[a] * v[a] - v[a - 1] * v[a - 1];
    }

    cout << fixed << setprecision(10) << ans * acos(-1);
}
