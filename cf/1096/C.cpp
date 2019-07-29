#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int gcd (int a, int b) {
    while (a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int d;
        cin >> d;

        int g = gcd(d, 180);
        int n = 180 / g;
        if (d / g > n - 2) {
            n *= 2;
        }
        cout << n << "\n";
    }
}
