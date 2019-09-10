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

    stack<bool> stk;
    string ans;
    int i = 0;
    while (i < (int)s.size()) {
        if (s.substr(i, 4) == "<UP>") {
            stk.push(true);
            i += 4;
        } else if (s.substr(i, 5) == "</UP>") {
            stk.pop();
            i += 5;
        } else if (s.substr(i, 6) == "<DOWN>") {
            stk.push(false);
            i += 6;
        } else if (s.substr(i, 7) == "</DOWN>") {
            stk.pop();
            i += 7;
        } else {
            if (stk.empty()) {
                ans += s[i];
            } else if (stk.top()) {
                ans += toupper(s[i]);
            } else {
                ans += tolower(s[i]);
            }
            i++;
        }
    }

    cout << ans;
}
