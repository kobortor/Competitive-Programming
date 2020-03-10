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
    
    string s;
    cin >> s;

    for (char ch = 'z'; ch >= 'b'; ch--) {
        string ns;
        for (int i = 0; i < (int)s.size(); i++) {
            bool can_remove = false;
            can_remove |= (i != 0 && s[i - 1] + 1 == s[i]);
            can_remove |= (i + 1 != (int)s.size() && s[i + 1] + 1 == s[i]);
            can_remove &= s[i] == ch;

            if (!can_remove) {
                ns += s[i];
            }
        }

        if (s.size() != ns.size()) {
            s = ns;
            ch++;
        }
    }

    cout << n - s.size();
}
