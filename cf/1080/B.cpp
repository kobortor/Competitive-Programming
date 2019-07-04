#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int sum(int x) {
    if (x % 2 == 0) {
        return x / 2;
    } else {
        return x / 2 - x;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << sum(r) - sum(l - 1) << "\n";
    }
}
