#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;

    ll distress = 0;
    while (n--) {
        char tp;
        ll amt;
        cin >> tp >> amt;
        if (tp == '+') {
            x += amt;
        } else if (x < amt) {
            distress++;
        } else {
            x -= amt;
        }
    }
    cout << x << " " << distress;
}
