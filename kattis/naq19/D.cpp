#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    bool printed = false;

    int y = 0;
    while (n--) {
        int x;
        cin >> x;

        while (y + 1 < x) {
            y++;
            cout << y << "\n";
            printed = true;
        }

        y = x;
    }

    if (!printed) {
        cout << "good job";
    }
}
