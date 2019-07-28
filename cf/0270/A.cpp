#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int a;
        cin >> a;

        if (360 % (180 - a) == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
