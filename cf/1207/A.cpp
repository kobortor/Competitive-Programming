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
        int b, p, f;
        cin >> b >> p >> f;
        b /= 2;
        
        int h, c;
        cin >> h >> c;

        if (h > c) {
            cout << min(b, p) * h + max(0, min(f, b - p)) * c << endl;
        } else {
            cout << min(b, f) * c + max(0, min(p, b - f)) * h << endl;
        }
    }
}
