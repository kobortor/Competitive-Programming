#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, h;
    cin >> n >> h;

    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x > h) {
            ans += 2;
        } else {
            ans++;
        }
    }

    cout << ans;
}
