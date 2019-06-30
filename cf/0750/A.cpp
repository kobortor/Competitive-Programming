#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    for (int a = 1; a <= n; a++) {
        if (5 * a * (a + 1) / 2 + k > 240) {
            cout << a - 1;
            return 0;
        }
    }

    cout << n;
}
