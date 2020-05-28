#include<bits/stdc++.h>

// Created by kobortor On 16:55:12 on 27-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll v(ll x, ll y) {
    return (x + y - 2) * (x + y - 1) / 2 + y;
}

ll sumup(ll x) {
    return x * (x + 1) / 2;
}

ll sumrange(ll x, ll y) {
    return sumup(y) - sumup(x - 1);
}

ll sumhelp(ll start, ll jmp, ll len) {
    return start * len + jmp * sumup(len - 1);
}

ll minpath(ll x1, ll y1, ll x2, ll y2) {
    return
        sumhelp(v(x1, y1), x1 + y1 - 1, x2 - x1) +
        sumhelp(v(x2, y1), x2 + y1, y2 - y1) +
        v(x2, y2);
}

ll maxpath(ll x1, ll y1, ll x2, ll y2) {
    return
        sumhelp(v(x1, y1), x1 + y1, y2 - y1) +
        sumhelp(v(x1, y2), x1 + y2 - 1, x2 - x1) +
        v(x2, y2);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2 || y1 > y2) {
            cout << "0\n";
        } else {
            cout << maxpath(x1, y1, x2, y2) - minpath(x1, y1, x2, y2) + 1 << "\n";
        }
    }
}
