#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    double tot = 0;
    while (n--) {
        double x, y;
        cin >> x >> y;
        tot += x * y;
    }

    cout << tot;
}
