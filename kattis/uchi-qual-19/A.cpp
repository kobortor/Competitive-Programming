#include <bits/stdc++.h>

using namespace std;

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x % 2) {
            cout << x << " is odd\n";
        } else {
            cout << x << " is even\n";
        }
    }
}
