#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int n, x;
        cin >> n >> x;

        int biggest_blow = 0;
        int biggest_diff = 0;
        while (n--) {
            int di, hi;
            cin >> di >> hi;
            biggest_blow = max(biggest_blow, di);
            biggest_diff = max(biggest_diff, di - hi);
        }

        if (biggest_diff == 0 && biggest_blow < x) {
            cout << "-1\n";
        } else if (biggest_blow < x) {
            cout << (x - biggest_blow + biggest_diff - 1) / biggest_diff + 1 << "\n";
        } else {
            cout << "1\n";
        }
    }
}
