#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    double d, h, v, e;
    cin >> d >> h >> v >> e;

    double r = d / 2;
    double pi = acos(-1);

    if (pi * r * r * e >= v) {
        cout << "NO";
        return 0;
    } else {
        cout << "YES\n";
        cout << fixed << setprecision(10) << pi * r * r * h / (v - pi * r * r * e);
    }
}
