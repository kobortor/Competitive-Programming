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
    getline(cin, s);

    int ans = 0;
    bool has_lft = false;

    for (char c : s) {
        if (c == ')') {
            if (has_lft) {
                ans--;
                has_lft = false;
            } else {
                ans++;
            }
        } else if (c == '(') {
            has_lft = true;
            ans++;
        } else if (c == '-' || c == ':' || c == ',' || c == ';') {
            has_lft = false;
        }
    }

    cout << ans;
}
