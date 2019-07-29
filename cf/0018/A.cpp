#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool right_helper(int x1, int y1, int x2, int y2) {
    return x1 * x2 + y1 * y2 == 0;
}

bool right(int x1, int y1, int x2, int y2, int x3, int y3) {
    int area =  (x2 - x1) * (y1 + y2) +
                (x3 - x2) * (y2 + y3) +
                (x1 - x3) * (y3 + y1);
    if (area == 0) return false;

    return  right_helper(x2 - x1, y2 - y1, x3 - x1, y3 - y1) ||
            right_helper(x1 - x2, y1 - y2, x3 - x2, y3 - y2) ||
            right_helper(x1 - x3, y1 - y3, x2 - x3, y2 - y3);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (right(x1, y1, x2, y2, x3, y3)) {
        cout << "RIGHT";
    } else if (
        right(x1 - 1, y1, x2, y2, x3, y3) ||
        right(x1 + 1, y1, x2, y2, x3, y3) ||
        right(x1, y1 - 1, x2, y2, x3, y3) ||
        right(x1, y1 + 1, x2, y2, x3, y3) ||
        right(x1, y1, x2 - 1, y2, x3, y3) ||
        right(x1, y1, x2 + 1, y2, x3, y3) ||
        right(x1, y1, x2, y2 - 1, x3, y3) ||
        right(x1, y1, x2, y2 + 1, x3, y3) ||
        right(x1, y1, x2, y2, x3 - 1, y3) ||
        right(x1, y1, x2, y2, x3 + 1, y3) ||
        right(x1, y1, x2, y2, x3, y3 - 1) ||
        right(x1, y1, x2, y2, x3, y3 + 1)) {
        cout << "ALMOST";
    } else {
        cout << "NEITHER";
    }
}
