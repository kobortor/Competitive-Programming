#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a, b;
    cin >> a >> b;

    int ans[3] = {0, 0, 0};
    for (int i = 1; i <= 6; i++) {
        int x = abs(a - i);
        int y = abs(b - i);
        if (x < y) {
            ans[0]++;
        } else if (x == y) {
            ans[1]++;
        } else {
            ans[2]++;
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2];
}
