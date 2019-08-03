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

    int v1 = 0, v2 = 0, v3 = 0;
    for (int a = 1, x; a <= n; a++) {
        cin >> x; v1 ^= x;
    }
    for (int a = 2, x; a <= n; a++) {
        cin >> x; v2 ^= x;
    }
    for (int a = 3, x; a <= n; a++) {
        cin >> x; v3 ^= x;
    }

    cout << (v1 ^ v2) << "\n" << (v2 ^ v3);

}
