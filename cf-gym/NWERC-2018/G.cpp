#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int wval[6969];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s; cin >> s;
    int n = s.size();

    wval['U'] = 1;
    wval['D'] = 1;

    vector<array<int,3>> ty;
    int cty = wval[s[0]];
    int clen = 1;
    int lv = s[0];

    for (int i = 1; i < n; i++) {
        if (wval[s[i]] == cty) {
            clen++;
            lv = s[i];
        }
        else {
            ty.push_back({cty, clen, lv});
            cty = wval[s[i]];
            clen = 1;
            lv = s[i];
        }
    }
    ty.push_back({cty, clen, lv});

    if (ty.back()[1] >= 3) {
        cout << "impossible\n";
        return 0;
    }

    int cx = 0, cy = 0;
    int len = 1e8;
    vector<pair<int,int>> ans;

    for (auto [ty, useless, lastval] : ty) {

        if (ty == 0) {

            ans.push_back({cx - len, cy});
            ans.push_back({cx + len, cy});

        }
        else {

            ans.push_back({cx, cy - len});
            ans.push_back({cx, cy + len});

        }

        if      (lastval == (int)('L')) cx -= (len - 1);
        else if (lastval == (int)('R')) cx += (len - 1);
        else if (lastval == (int)('U')) cy += (len - 1);
        else                            cy -= (len - 1);

        len = (len / 2) - 3;

    }

    for (auto &[x, y] : ans) {
        x -= cx;
        y -= cy;
    }

    cout << (-cx) << " " << (-cy) << "\n";
    cout << ans.size() << "\n";

    for (auto [x, y] : ans)
        cout << x << " " << y << "\n";

}
