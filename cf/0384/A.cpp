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

    cout << (n * n + 1) / 2 << '\n';
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if ((a + b) % 2 == 0) {
                cout << 'C';
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}
