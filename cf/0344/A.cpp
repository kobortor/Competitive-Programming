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

    int prv;
    cin >> prv;

    int ans = 1;

    for (int a = 1; a < n; a++) {
        int cur;
        cin >> cur;
        if (cur != prv) {
            ans++;
            prv = cur;
        }
    }

    cout << ans;
}
