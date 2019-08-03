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

    set<int> xs, ys;
    while (n--) {
        int x, y;
        cin >> x >> y;
        xs.insert(x);
        ys.insert(y);
    }

    cout << min(xs.size(), ys.size());
}
