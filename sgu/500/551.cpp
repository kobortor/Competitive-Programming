#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, t1, t2;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> t1 >> t2;

    int lo = 0, hi = (t1 + t2) * n;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int finished = mid / t1 + mid / t2;

        if (finished < n) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    //last thing should start at lo
    int nt1 = (lo + t1 - 1) / t1;
    int nt2 = (lo + t2 - 1) / t2;

    cout << nt1 + nt2 << " " << max(nt1 * t1, nt2 * t2);
}
