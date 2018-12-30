#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int y, b, r;
    cin >> y >> b >> r;

    int ans = min(y, min(b - 1, r - 2));

    ans = max(ans, 0);
    cout << 3 * ans + 3 << endl;
}
