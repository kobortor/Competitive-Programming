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
        string s;
        cin >> s;

        sort(allof(s));
        string r = s;
        reverse(allof(r));
        if (s == r) {
            cout << "-1\n";
        } else {
            cout << s << "\n";
        }
    }
}
