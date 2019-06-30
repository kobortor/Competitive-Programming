#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int w, h, k;
    cin >> w >> h >> k;

    int ans = 0;
    for (int a = 0; a < w; a++) {
        for (int b = 0; b < h; b++) {
            int d = min(min(a, w - a - 1), min(b, h - b - 1));

            if (d % 2 == 0 && d / 2 < k) {
                ans++;
            }
        }
    }

    cout << ans;
}
