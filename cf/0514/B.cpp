#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, x0, y0;
    cin >> n >> x0 >> y0;

    set<pii> st;
    while (n--) {
        int x, y;
        cin >> x >> y;
        x -= x0;
        y -= y0;

        int g = gcd(abs(x), abs(y));
        x /= g; y /= g;

        if (pii(x, y) < pii(-x, -y)) {
            st.insert({x, y});
        } else {
            st.insert({-x, -y});
        }
    }

    cout << st.size();
}
