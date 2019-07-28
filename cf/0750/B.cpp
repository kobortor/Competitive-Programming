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

    int pos = 0;
    while (n--) {
        int mv;
        string s;
        cin >> mv >> s;

        if (s == "North") {
            if (pos < mv) {
                cout << "NO";
                return 0;
            }
            pos -= mv;
        } else if (s == "South") {
            if (pos + mv > 20000) {
                cout << "NO";
                return 0;
            }
            pos += mv;
        } else if (pos == 0 || pos == 20000) {
            cout << "NO";
            return 0;
        }
    }

    if (pos == 0) cout << "YES";
    else cout << "NO";
}
