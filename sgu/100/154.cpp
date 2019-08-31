#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n_zeros (int n) {
    int ans = 0;
    while (n) {
        ans += n / 5;
        n /= 5;
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int Q;
    cin >> Q;

    // Apparently in russia 1 is a natural number >:(
    int lo = 1, hi = 1000000000;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (n_zeros(mid) < Q) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    if (n_zeros(lo) == Q) cout << lo;
    else cout << "No solution";
}
