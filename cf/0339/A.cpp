#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    sort(allof(s));
    for (int a = s.size() / 2; a < (int)s.size(); a++) {
        cout << s[a];
        if (a + 1 != (int)s.size()) {
            cout << "+";
        }
    }
}
