#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, d;
    cin >> n >> d;

    int m;
    cin >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;

        if (x + y >= d &&
            x + y <= 2 * n - d &&
            abs(y - x) <= d) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
