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

    for (int a = n;; a /= 2) {
        for (int b = 0; b < n; b += a) {
            if (is_sorted(v.begin() + b, v.begin() + b + a)) {
                cout << a;
                return 0;
            }
        }
    }
}
