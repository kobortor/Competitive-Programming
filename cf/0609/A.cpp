#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int &i : v) cin >> i;

    sort(allof(v), greater<int>());
    for (int a = 0; a < n; a++) {
        if (v[a] >= m) {
            cout << a + 1;
            break;
        } else {
            m -= v[a];
        }
    }
}
