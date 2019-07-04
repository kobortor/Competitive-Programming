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

    if (n % 2 == 1) {
        cout << -1;
    } else {
        for (int a = 1; a <= n; a++) {
            cout << n - a + 1 << " ";
        }
    }
}
