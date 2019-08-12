#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m, h;
    cin >> n >> m >> h;

    int tot = 0;

    vector<int> s(m);
    for (int &i : s) {
        cin >> i;
        tot += i;
    }

    if (tot < n) {
        cout << -1;
        return 0;
    }

    double ans = 1;

    int sh = s[h - 1];

    tot--;
    sh--;

    for (int a = 0; a < n - 1; a++) {
        ans = ans * (double)(tot - sh - a) / (tot - a);
    }

    cout << fixed << setprecision(10) << 1.0 - ans;
}
