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

    int cnt[2] = {0, 0};
    for (int a = 0; a < n; a++) {
        int tp, x, y;
        cin >> tp >> x >> y;
        cnt[tp - 1] += x - y;
    }

    if (cnt[0] >= 0) {
        cout << "LIVE\n";
    } else {
        cout << "DEAD\n";
    }

    if (cnt[1] >= 0) {
        cout << "LIVE\n";
    } else {
        cout << "DEAD\n";
    }
}
