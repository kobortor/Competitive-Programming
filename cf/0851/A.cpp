#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k, t;
    cin >> n >> k >> t;

    if (t <= k) {
        cout << t;
    } else if (t <= n) {
        cout << k;
    } else {
        cout << k - (t - n);
    }
}
