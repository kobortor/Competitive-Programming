#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    double best = 1e9;
    while (n--) {
        double x, y, s;
        cin >> x >> y >> s;
        best = min(best, hypot(x - a, y - b) / s);
    }

    cout << fixed << setprecision(10) << best;
}
