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
        ll s, a, b, c;
        cin >> s >> a >> b >> c;

        cout << s / c + s / c / a * b << "\n";
    }
}
