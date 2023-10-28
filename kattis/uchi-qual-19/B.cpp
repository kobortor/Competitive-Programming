#include <bits/stdc++.h>

using namespace std;

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<string> v(n);
    for (string &s : v) {
        cin >> s;
    }
    if (is_sorted(v.begin(), v.end())) {
        cout << "INCREASING\n";
    } else {
        reverse(v.begin(), v.end());
        if (is_sorted(v.begin(), v.end())) {
            cout << "DECREASING\n";
        } else {
            cout << "NEITHER\n";
        }
    }
}
