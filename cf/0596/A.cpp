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

    int minx = 1e9, maxx = -1e9;
    int miny = 1e9, maxy = -1e9;

    while (n--) {
        int x, y;
        cin >> x >> y;
        minx = min(minx, x);
        maxx = max(maxx, x);

        miny = min(miny, y);
        maxy = max(maxy, y);
    }

    if (minx == maxx || miny == maxy) {
        cout << -1;
    } else {
        cout << (maxx - minx) * (maxy - miny);
    }
}
