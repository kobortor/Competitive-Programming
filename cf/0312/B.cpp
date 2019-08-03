#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(10) << a * d / (b * d - (b - a) * (d - c));
}
