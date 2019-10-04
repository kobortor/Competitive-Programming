#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<int> posn[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    for (int a = 0; a < (int)s.size(); a++) {
        posn[s[a] - 'a'].insert(a);
    }

    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;

        if (tp == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            pos--;

            posn[s[pos] - 'a'].erase(pos);

            s[pos] = c;
            posn[s[pos] - 'a'].insert(pos);
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;

            int ans = 0;
            for (int a = 0; a < 26; a++) {
                auto iter = posn[a].lower_bound(l);
                if (iter != posn[a].end() && *iter <= r) {
                    ans++;
                }
            }

            cout << ans << "\n";
        }
    }
}
