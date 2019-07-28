#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;
    while (q--) {
        vector<ll> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(allof(v));

        if (v[2] >= v[1] - v[0]) {
            cout << (v[0] + v[1] + v[2]) / 2 << "\n";
        } else {
            cout << v[0] + v[2] << "\n";
        }
    }

}
