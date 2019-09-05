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

    list<char> lst;
    auto iter = lst.begin();

    for (char c : s) {
        if (c == 'L') {
            if (iter != lst.begin()) {
                iter--;
            }
        } else if (c == 'R') {
            if (iter != lst.end()) {
                iter++;
            }
        } else {
            lst.insert(iter, c);
        }
    }

    string ans(allof(lst));

    cout << ans;
}
