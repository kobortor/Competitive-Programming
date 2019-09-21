#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int &i : v) cin >> i;

        int inc = 0, dec = 0;
        for (int a = 1; a < n; a++) {
            if (v[a] == v[a - 1] + 1) inc++;
            if (v[a] == v[a - 1] - 1) dec++;
        }

        if (v[0] == v.back() + 1) inc++;
        if (v[0] == v.back() - 1) dec++;

        if (inc == n - 1 || dec == n - 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
