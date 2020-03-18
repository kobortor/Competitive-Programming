#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        bool bad = false;

        int x, y;
        cin >> x;
        while (--n) {
            cin >> y;
            bad |= (x ^ y) & 1;
        }

        if (!bad) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
