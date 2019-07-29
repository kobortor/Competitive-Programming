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

    pii prv;
    cin >> prv.first >> prv.second;
    cin >> prv.first >> prv.second;
    pii rhs = {1, 0};

    int ans = 0;

    for (int a = 1; a < n; a++) {
        pii nxt;
        cin >> nxt.first >> nxt.second;

        pii diff = {nxt.first - prv.first, nxt.second - prv.second};

        if (diff.first) diff.first /= abs(diff.first);
        if (diff.second) diff.second /= abs(diff.second);

        if (diff != rhs) {
            ans++;
        }

        rhs = pii(diff.second, -diff.first);

        prv = nxt;
    }

    cout << ans;
}
