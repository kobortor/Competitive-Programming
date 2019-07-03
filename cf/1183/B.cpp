#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;

        int lo = -1e9, hi = +1e9;
        while (n--){
            int ai;
            cin >> ai;
            lo = max(lo, ai - k);
            hi = min(hi, ai + k);
        }

        if (lo <= hi) {
            cout << hi << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
