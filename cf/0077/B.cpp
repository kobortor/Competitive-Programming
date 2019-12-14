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
        // x^2 + sqrt(p) * x + q = 0 has 
        //   real roots iff p - 4q >= 0
        double a, b;
        cin >> a >> b;

        cout << fixed << setprecision(15);

        if (b == 0) {
            cout << 1 << endl;
        } else if (a == 0) {
            cout << 0.5 << endl;
        } else if (a > b * 4) {
            // 1 - (2 * b * b) / (2 * a * b)
            cout << 1 - b / a << endl;
        } else {
            double remain = b - a / 4;
            cout << 1 - (b + remain) / (4 * b) << endl;
        }
    }
}
