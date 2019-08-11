#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    int ans = 0;

    while (n--) {
        string ai;
        cin >> ai;

        if (count(allof(ai), '4') + count(allof(ai), '7') <= k) {
            ans++;
        }
    }

    cout << ans;
}
