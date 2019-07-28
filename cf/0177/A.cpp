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

    int ans = 0;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            int x;
            cin >> x;

            if (a == b ||
                a == n / 2 ||
                b == n / 2 ||
                a + b == n - 1) {
                ans += x;
            }
        }
    }

    cout << ans;
}
