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

    int lft = 0, rht = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x < 0) lft++;
        else rht++;
    }

    if (lft <= 1 || rht <= 1) cout << "Yes";
    else cout << "No";
}
