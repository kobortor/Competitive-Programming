#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string x, y;
    cin >> x;

    for (int a = 0; a < 5; a++) {
        cin >> y;
        if (x[0] == y[0] || x[1] == y[1]) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}
