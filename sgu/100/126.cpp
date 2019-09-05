#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int gcd (int a, int b) {
    if (!a) return b;
    if (!b) return a;

    while (a % b) {
        a %= b;
        swap (a, b);
    }
    return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int A, B;
    cin >> A >> B;

    int AA = A, BB = B;

    int ans = 0;
    while (true) {
        if (A > B) swap (A, B);
        if (AA > BB) swap (AA, BB);

        if (A != 0 && B != 0) {
            int G = gcd (A, B);
            if ((A + B) / G % 2 != 0) {
                cout << -1;
                return 0;
            }
        }

        if (A == 0) {
            cout << ans;
            return 0;
        }

        if (ans != 0 && A == AA && B == BB) {
            cout << -1;
            return 0;
        }

        B -= A;
        A *= 2;

        ////
        BB -= AA;
        AA *= 2;

        if (AA > BB) swap (AA, BB);

        BB -= AA;
        AA *= 2;

        ans++;
    }
}
